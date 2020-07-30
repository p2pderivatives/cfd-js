/* eslint-disable @typescript-eslint/no-explicit-any */
/* eslint-disable require-jsdoc */
'use strict';
import fs from 'fs';
import path from 'path';
import {Project} from 'ts-morph';
// FIXME(k-matsuzawa): Consider splitting the file.

interface JsonObjectCommonType {
  namespace: string | string[];
  commonHeader: string;
};

interface ClassMapType {
  [key: string]: any;
};

interface CollectMapDataResponse {
  type: string;
  map: ClassMapType;
  list: any[];
};

interface ParameterType {
  name: string;
  type: string;
};

interface TsAppendFunctionData {
  name: string;
  parameters: ParameterType[];
  returnType: string;
};

// ----------------------------------------------------------------------------
// debug log function
// ----------------------------------------------------------------------------
// eslint-disable-next-line @typescript-eslint/no-unused-vars
let debugLog = function(...args: any | any[]) {
  // do nothing
};

// ----------------------------------------------------------------------------
// json data class
// ----------------------------------------------------------------------------
class JsonMappingData {
  name: string;
  methodName: string;
  variableName: string;
  initValue: string | number | boolean;
  className: string;
  childList: {[key: string]: JsonMappingData};
  parent: null;
  isOutputStruct: boolean;
  isArray: boolean;
  isObject: boolean;
  isRequire: boolean;
  type: string;
  structType: string;
  constructor(name: string, type: string, initValue: string | number | boolean,
      className: string, isOutputStruct = true) {
    this.name = name;
    this.methodName = (() => {
      const replacedMethodName = this.name.replace(/-/gi, '_');
      return replacedMethodName.charAt(0).toUpperCase() +
        replacedMethodName.slice(1);
    })();
    this.variableName = (() => {
      const replacedVariableName = this.name.replace(/-/gi, '_');
      return replacedVariableName.split(/(?=[A-Z])/).join('_').toLowerCase();
    })();
    this.type = type;
    this.structType = `${type}Struct`;
    this.setType(type);
    this.initValue = initValue;
    this.className = className;
    this.childList = {};
    this.parent = null;
    this.isOutputStruct = isOutputStruct;
    this.isArray = false;
    this.isObject = false;
    this.isRequire = false;
    // Reserved word support.
    // TODO(k-matsuzawa): If the number increases, make a list.
    if (this.variableName == 'asm') this.variableName = `${this.variableName}_`;
  }

  setType(type: string) {
    this.type = type;
    this.structType = `${type}Struct`;
    if (type.startsWith('JsonValueVector')) {
      const typeName = type.split('<')[1].split('>')[0];
      this.structType = `std::vector<${typeName}>`;
    } else if (type.startsWith('JsonObjectVector')) {
      const typeName = type.split('<')[1].split(',')[0].split('>')[0];
      this.structType = `std::vector<${typeName}Struct>`;
    }
  }

  setRequired(requireInfo: string) {
    if (requireInfo === 'require') {
      this.isRequire = true;
    }
  }

  setTypeStruct(type: string, structType: any) {
    this.type = type;
    this.structType = structType;
    if (type.startsWith('JsonValueVector')) {
      const typeName = type.split('<')[1].split('>')[0];
      this.structType = `std::vector<${typeName}>`;
    } else if (type.startsWith('JsonObjectVector')) {
      const typeName = type.split('<')[1].split(',')[0].split('>')[0];
      this.structType = `std::vector<${typeName}Struct>`;
    }
  }

  toString() {
    const str = `[JsonMappingData] ${this.name}:${this.type}:${this.className}`;
    // for debug code.
    // for (const key in this.childList) {
    //   str += "\n - "
    //   str += this.childList[key].toString()
    // }
    return str;
  }

  collectMapData(map: ClassMapType, list: any[],
      isRequest: boolean): CollectMapDataResponse {
    if (this.type.startsWith('JsonValueVector') || this.type.startsWith('JsonObjectVector')) {
      for (const key in this.childList) {
        if (!{}.hasOwnProperty.call(this.childList, key)) continue;
        if (this.childList[key]) {
          const ret = this.childList[key].collectMapData(map, list, isRequest);
          return {type: ret['type'] + '[]', map: ret['map'], list: ret['list']};
        }
        break;
      }
      throw Error('Illegal state.');
    } else if (this.type === 'ErrorResponseBase') {
      const clsName = 'ErrorResponse';
      const props = [];
      let tmpMap = map;
      let tmpList = list;
      for (const key in this.childList) {
        if (this.childList[key]) {
          const name = this.childList[key].name + (this.childList[key].isRequire ? '' : '?');
          const ret = this.childList[key].collectMapData(
              tmpMap, tmpList, isRequest);
          const type = ret['type'];
          tmpMap = ret['map'];
          tmpList = ret['list'];
          if (name === 'isOutputStruct') {
            continue;
          }
          props.push({name: name, type: type});
        }
      }
      tmpMap[clsName] = props;
      tmpList.push(clsName);
      return {type: clsName, map: tmpMap, list: tmpList};
    } else if (Object.keys(this.childList).length > 0) {
      // my class name
      const props = [];
      let tmpMap = map;
      let tmpList = list;
      for (const key in this.childList) {
        if (this.childList[key]) {
          let name = this.childList[key].name + (this.childList[key].isRequire ? '' : '?');
          const ret = this.childList[key].collectMapData(
              tmpMap, tmpList, isRequest);
          debugLog('prop : ', ret);
          const type = ret['type'];
          tmpMap = ret['map'];
          tmpList = ret['list'];
          if (name.indexOf('-') > 0) {
            name = '\'' + name + '\'';
          }
          props.push({name: name, type: type});
        }
      }
      debugLog('props = ', props);
      tmpMap[this.type] = props;
      tmpList.push(this.type);
      return {type: this.type, map: tmpMap, list: tmpList};
    } else {
      let type = '';
      if (this.type === 'std::string') {
        type = 'string';
      } else if (this.type === 'bool') {
        type = 'boolean';
      } else if ((this.type === 'int64_t') || (this.type === 'uint64_t')) {
        type = (isRequest) ? 'bigint | number' : 'bigint';
      } else {
        type = 'number';
      }
      return {type: type, map: map, list: list};
    }
  }

  getFunctionName() {
    let result = '';
    if (this.type.indexOf('Request') >= 0) {
      result = this.type.substring(0, this.type.indexOf('Request'));
    } else if (this.type.indexOf('Response') >= 0) {
      result = this.type.substring(0, this.type.indexOf('Response'));
    }
    // ignore target
    if (result === 'Error') {
      return '';
    }
    return result;
  }
}

// ----------------------------------------------------------------------------
// json data class
// ----------------------------------------------------------------------------
class JsonData {
  tjsonData: any;
  requestData: JsonMappingData | null | undefined;
  responseData: JsonMappingData | null | undefined;
  constructor(tjsonData: any, requestData: JsonMappingData | null | undefined,
      responseData: JsonMappingData | null | undefined) {
    this.tjsonData = tjsonData;
    this.requestData = requestData;
    this.responseData = responseData;
  }
}

// ----------------------------------------------------------------------------
// array check function
// ----------------------------------------------------------------------------
function isArray(obj: any) {
  return (obj instanceof Array);
  // return Object.prototype.toString.call(obj) === '[object Array]';
}

// ----------------------------------------------------------------------------
// analyze function
// ----------------------------------------------------------------------------
const analyzeJson = (jsonObj: any | any[],
    objName = '', arraytype = '') => {
  debugLog(`analyzeJson obj=${objName}`);
  let result;
  if (typeof jsonObj == 'string') {
    result = new JsonMappingData(objName, 'std::string', jsonObj, '');
  } else if (typeof jsonObj == 'number') {
    result = new JsonMappingData(objName, 'int64_t', jsonObj, '');
  } else if (typeof jsonObj == 'boolean') {
    result = new JsonMappingData(objName, 'boolean', jsonObj, '');
  } else if (jsonObj) {
    const objKey = Object.keys(jsonObj);
    const objValues = Object.values(jsonObj);
    // if (objKey == 0) { // array
    if (isArray(jsonObj)) {
      debugLog(`read arr = ${objValues}`);
      let pastType = '';
      let firstMap: JsonMappingData | null = null;
      for (const item in jsonObj) {
        if (!{}.hasOwnProperty.call(jsonObj, item)) continue;
        const tempChild = analyzeJson(jsonObj[item], objName);
        if (!tempChild) {
          // error
        } else if (pastType == '') {
          firstMap = tempChild;
          pastType = tempChild.type;
        } else if (pastType != tempChild.type) {
          console.log('illegal list elements. fail.');
          return result;
        }
      }
      debugLog(`pastType = ${pastType}`);
      if (pastType == '') {
        // field and class name is set by the caller.
        result = new JsonMappingData('', '', '', '');
      } else {
        if ((typeof objValues[0] == 'string') || (typeof objValues[0] == 'number') ||
          (typeof objValues[0] == 'boolean')) {
          // array of string or number.
          if ((typeof objValues[0] == 'number') && (arraytype)) {
            result = new JsonMappingData(objName, `JsonValueVector<${arraytype}>`, '', '');
            if (firstMap !== null) firstMap.setType(arraytype);
          } else {
            result = new JsonMappingData(objName, `JsonValueVector<${pastType}>`, '', '');
          }
        } else {
          // array of object
          result = new JsonMappingData(objName, `JsonObjectVector<${pastType}, ${pastType}Struct>`, '', '');
        }
      }
      if (firstMap !== null) {
        result.childList[0] = firstMap;
      }
      result.isArray = true;
      debugLog(`list_type = ${result.type}`);
      debugLog(`clist_type = ${result.childList[0].type}`);
    } else { // object
      debugLog(`read keys = ${objKey}`);
      let className = objName;
      if (':class' in jsonObj) {
        if (typeof jsonObj[':class'] === 'string') {
          className = jsonObj[':class'];
          debugLog(`read className = ${className}`);
        }
      }
      let isOutputStruct = true;
      if (':isOutputStruct' in jsonObj) {
        if (typeof jsonObj[':isOutputStruct'] === 'boolean') {
          isOutputStruct = jsonObj[':isOutputStruct'];
          debugLog(`set ${className}, isOutputStruct=${isOutputStruct}`);
        }
      }
      // Class name is set by the caller.
      result = new JsonMappingData(objName, className, '', '', isOutputStruct);
      result.isObject = true;
      // Stored in temporary map to maintain sort order.
      const tmpMap: {[key: string]: JsonMappingData} = {};
      const requireMap: {[key: string]: string} = {};
      const rarraytypeMap: {[key: string]: string} = {};
      for (const key in jsonObj) {
        if (!{}.hasOwnProperty.call(jsonObj, key)) continue;
        if (key != ':class') {
          if (key.lastIndexOf(':type') >= 0) {
            const keyName = key.split(':')[0];
            if (tmpMap[keyName]) {
              tmpMap[keyName].setType(jsonObj[key]);
            } else {
              const data = new JsonMappingData(keyName, jsonObj[key], '', className, isOutputStruct);
              tmpMap[keyName] = data;
              debugLog(`set JsonMappingData = ${keyName}`);
            }
          }
          if (key.lastIndexOf(':require') >= 0) {
            const keyName = key.split(':')[0];
            requireMap[keyName] = jsonObj[key];
          }
          if (key.lastIndexOf(':arraytype') >= 0) {
            const keyName = key.split(':')[0];
            rarraytypeMap[keyName] = jsonObj[key];
          }
        }
      }

      for (const key in jsonObj) {
        if (!{}.hasOwnProperty.call(jsonObj, key)) continue;
        if (key.indexOf(':') == -1) {
          debugLog(`read key = ${key}`);
          const value = jsonObj[key];
          if (tmpMap[key]) {
            result.childList[key] = tmpMap[key];
            result.childList[key].initValue = value;
          } else {
            // type check
            let typeStr = '';
            if (typeof value == 'string') {
              typeStr = 'std::string';
            } else if (typeof value == 'number') {
              typeStr = 'int64_t';
            } else if (typeof value == 'boolean') {
              typeStr = 'bool';
            } else if (value) {
              const objKey2 = Object.keys(value);
              if ((typeof objKey2 === 'number') && (objKey2 == 0)) { // array
                // Should I examine the element first?
                typeStr = '';
              } else { // object
                typeStr = '';
              }
            }
            result.childList[key] = new JsonMappingData(
                key, typeStr, value, className);
          }
          if (requireMap[key]) {
            result.childList[key].setRequired(requireMap[key]);
          }
          const tempChild = analyzeJson(value, key, rarraytypeMap[key]);
          if (tempChild) {
            if (result.childList[key].type == '') {
              result.childList[key].setTypeStruct(
                  tempChild.type, tempChild.structType);
              if ((result.childList[key].type.indexOf('JsonObjectVector') >= 0) ||
                (result.childList[key].type.indexOf('JsonValueVector') >= 0)) {
                result.childList[key].isArray = true;
              } else {
                result.childList[key].isObject = true;
              }
            }
            result.childList[key].childList = tempChild.childList;
            result.childList[key].className = className;
          }
        }
      }
    }
  } else {
    console.log('empty value.');
  }
  return result;
};

interface JsonMapDataType {
  isObject: boolean;
  childList: any[];
  isArray: boolean;
}

// ----------------------------------------------------------------------------
// analize child class function
// ----------------------------------------------------------------------------
const getChildClasses = (jsonMapData: JsonMappingData,
    list: JsonMappingData[]) => {
  if (!jsonMapData) {
    // do nothing
  } else if (jsonMapData.isObject) {
    for (const key in jsonMapData.childList) {
      if (jsonMapData.childList[key]) {
        if (jsonMapData.childList[key].isObject ||
            jsonMapData.childList[key].isArray) {
          getChildClasses(jsonMapData.childList[key], list);
        }
      }
    }
    list.push(jsonMapData);
  } else if (jsonMapData.isArray) {
    getChildClasses(jsonMapData.childList[0], list);
  }
};

// ----------------------------------------------------------------------------
// generate cpp file source function
// ----------------------------------------------------------------------------
const generateFileSource = (filename: string, headerName: string | string[],
    classList: any[], jsonSetting: JsonObjectCommonType | undefined) => {
  const result = [];
  const namespace = (!jsonSetting) ? '' : jsonSetting.namespace;
  const includeNolint = (headerName.indexOf('/') >= 0) ? '' : '  // NOLINT';

  // header
  const sourceFileHeader = `// Copyright 2019 CryptoGarage
/**
 * @file ${filename}
 *
 * @brief JSON mapping file (auto generate)
 */
#include <set>
#include <string>
#include <vector>

#include "${headerName}"${includeNolint}
`;
  result.push(sourceFileHeader);

  if (isArray(namespace)) {
    for (let idx = 0; idx < namespace.length; ++idx) {
      result.push(`namespace ${namespace[idx]} {`);
    }
  } else {
    result.push(`namespace ${namespace} {`);
  }

  const sourceFileHeader2 = `
using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;
// clang-format off
// @formatter:off\
`;
  const sourceFileFooter = `
// @formatter:on
// clang-format on
`;
  result.push(sourceFileHeader2);

  if (classList) {
    for (const data in classList) {
      if (!{}.hasOwnProperty.call(classList, data)) continue;
      result.push(classList[data]);
    }
  }

  result.push(sourceFileFooter);

  if (isArray(namespace)) {
    for (let idx = namespace.length - 1; idx >= 0; --idx) {
      result.push(`}  // namespace ${namespace[idx]}`);
    }
  } else {
    result.push(`}  // namespace ${namespace}`);
  }
  result.push('');

  return result.join('\n');
};


// ----------------------------------------------------------------------------
// generate cpp class source function
// ----------------------------------------------------------------------------
const generateClassSource = (req: JsonMappingData | null | undefined,
    res: JsonMappingData | null | undefined) => {
  const result = [];
  const processedList: any[] = [];

  if (req || res) {
    const list: JsonMappingData[] = [];
    if (req) list.push(req);
    if (res) list.push(res);
    for (const data of list) {
      if (!data) continue;
      // sort by classname
      // for child elements
      const mapList: JsonMappingData[] = [];
      getChildClasses(data, mapList);
      debugLog(`mapList = ${mapList}`);

      for (const mapKey in mapList) {
        if (!{}.hasOwnProperty.call(mapList, mapKey)) continue;
        const mapData = mapList[mapKey];
        if (processedList.includes(mapData.type)) {
          continue;
        }
        const sourceClassHeader = `
// ------------------------------------------------------------------------
// ${mapData.type}
// ------------------------------------------------------------------------
cfd::core::JsonTableMap<${mapData.type}>
  ${mapData.type}::json_mapper;
std::vector<std::string> ${mapData.type}::item_list;

void ${mapData.type}::CollectFieldName() {
  if (!json_mapper.empty()) {
    return;
  }
  cfd::core::CLASS_FUNCTION_TABLE<${mapData.type}> func_table;  // NOLINT
`;
        result.push(sourceClassHeader);

        for (const childKey in mapData.childList) {
          if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
          const childData = mapData.childList[childKey];
          // start
          const addJsonMapperComment = `\
  func_table = {
    ${mapData.type}::Get${childData.methodName}String,
    ${mapData.type}::Set${childData.methodName}String,
    ${mapData.type}::Get${childData.methodName}FieldType,
  };
  json_mapper.emplace("${childData.name}", func_table);
  item_list.push_back("${childData.name}");\
`;
          // end
          result.push(addJsonMapperComment);
        }
        result.push('}');

        if (mapData.isOutputStruct) {
          result.push('');
          result.push(`void ${mapData.type}::ConvertFromStruct(`);
          result.push(`    const ${mapData.structType}& data) {`);
          for (const childKey in mapData.childList) {
            if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
            const childData = mapData.childList[childKey];
            if (childData.isObject || childData.isArray) {
              const str = `  ${childData.variableName}_.ConvertFromStruct(data.${childData.variableName});`;
              if (str.length > 80) {
                result.push(`  ${childData.variableName}_.ConvertFromStruct(`);
                result.push(`      data.${childData.variableName});`);
              } else {
                result.push(`  ${childData.variableName}_.ConvertFromStruct(data.${childData.variableName});`);
              }
            } else {
              result.push(`  ${childData.variableName}_ = data.${childData.variableName};`);
            }
          }
          result.push(`  ignore_items = data.ignore_items;`);
          result.push('}');

          result.push('');
          result.push(`${mapData.structType} ${mapData.type}::ConvertToStruct() const {  // NOLINT`);
          result.push(`  ${mapData.structType} result;`);
          for (const childKey in mapData.childList) {
            if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
            const childData = mapData.childList[childKey];
            if (childData.isObject || childData.isArray) {
              const str = `  result.${childData.variableName} = ${childData.variableName}_.ConvertToStruct();`;
              if (str.length > 80) {
                result.push(`  result.${childData.variableName} = ${childData.variableName}_.ConvertToStruct();  // NOLINT`);
              } else {
                result.push(`  result.${childData.variableName} = ${childData.variableName}_.ConvertToStruct();`);
              }
            } else {
              result.push(`  result.${childData.variableName} = ${childData.variableName}_;`);
            }
          }
          result.push(`  result.ignore_items = ignore_items;`);
          result.push('  return result;');
          result.push('}');
        }

        processedList.push(mapData.type);
      }
    }
  }

  return result.join('\n');
};


// ----------------------------------------------------------------------------
// generate class header function
// ----------------------------------------------------------------------------
const generateClassHeaderData = (mapData: JsonMappingData,
    exportDefine: string) => {
  const classHeader = `
// ------------------------------------------------------------------------
// ${mapData.type}
// ------------------------------------------------------------------------
/**
 * @brief JSON-API (${mapData.type}) class
 */
class ${exportDefine}${mapData.type}
  : public cfd::core::JsonClassBase<${mapData.type}> {
 public:
  ${mapData.type}() {
    CollectFieldName();
  }
  virtual ~${mapData.type}() {
    // do nothing
  }
  /**
   * @brief collect field name.
   */
  static void CollectFieldName();
`;
  return classHeader;
};


// ----------------------------------------------------------------------------
// generate object function by header
// ----------------------------------------------------------------------------
const generateObjectFunctionByHeader = (mapData: JsonMappingData,
    childData: JsonMappingData) => {
  // Rename method name because equals windows macro's function.
  const methodName = (childData.methodName === 'KValue') ?
      'K_Value' : childData.methodName;

  const objectFunctions = `\
  /**
   * @brief Get of ${childData.name}.
   * @return ${childData.name}
   */
  ${childData.type}& Get${methodName}() {  // NOLINT
    return ${childData.variableName}_;
  }
  /**
   * @brief Set to ${childData.name}.
   * @param[in] ${childData.variableName}    setting value.
   */
  void Set${methodName}(  // line separate
      const ${childData.type}& ${childData.variableName}) {  // NOLINT
    this->${childData.variableName}_ = ${childData.variableName};
  }
  /**
   * @brief Get data type of ${childData.name}.
   * @return Data type of ${childData.name}.
   */
  static std::string Get${childData.methodName}FieldType() {
    return "${childData.type}";  // NOLINT
  }
  /**
   * @brief Get json string of ${childData.name} field.
   * @param[in,out] obj     class object
   * @return JSON string.
   */
  static std::string Get${childData.methodName}String(  // line separate
      const ${mapData.type}& obj) {  // NOLINT
    // Do not set to const, because substitution of member variables
    // may occur in pre / post processing inside Serialize
    return obj.${childData.variableName}_.Serialize();
  }
  /**
   * @brief Set json object to ${childData.name} field.
   * @param[in,out] obj     class object
   * @param[in] json_value  JSON object
   */
  static void Set${childData.methodName}String(  // line separate
      ${mapData.type}& obj,  // NOLINT
      const UniValue& json_value) {
    obj.${childData.variableName}_.DeserializeUniValue(json_value);
  }
`;
  return objectFunctions;
};

// ----------------------------------------------------------------------------
// generate value function by header
// ----------------------------------------------------------------------------
const generateValueFunctionByHeader = (mapData: JsonMappingData,
    childData: JsonMappingData) => {
  // Rename method name because equals windows macro's function.
  const methodName = (childData.methodName === 'KValue') ?
      'K_Value' : childData.methodName;

  const valueFunctions = `\
  /**
   * @brief Get of ${childData.name}
   * @return ${childData.name}
   */
  ${childData.type} Get${methodName}() const {
    return ${childData.variableName}_;
  }
  /**
   * @brief Set to ${childData.name}
   * @param[in] ${childData.variableName}    setting value.
   */
  void Set${methodName}(  // line separate
    const ${childData.type}& ${childData.variableName}) {  // NOLINT
    this->${childData.variableName}_ = ${childData.variableName};
  }
  /**
   * @brief Get data type of ${childData.name}
   * @return Data type of ${childData.name}
   */
  static std::string Get${childData.methodName}FieldType() {
    return "${childData.type}";
  }
  /**
   * @brief Get json string of ${childData.name} field.
   * @param[in,out] obj     class object.
   * @return JSON string
   */
  static std::string Get${childData.methodName}String(  // line separate
      const ${mapData.type}& obj) {  // NOLINT
    return cfd::core::ConvertToString(obj.${childData.variableName}_);
  }
  /**
   * @brief Set json object to ${childData.name} field.
   * @param[in,out] obj     class object.
   * @param[in] json_value  JSON object.
   */
  static void Set${childData.methodName}String(  // line separate
      ${mapData.type}& obj,  // NOLINT
      const UniValue& json_value) {
    cfd::core::ConvertFromUniValue(  // line separate
      obj.${childData.variableName}_, json_value);
  }
`;
  return valueFunctions;
};

// ----------------------------------------------------------------------------
// generate class field by header
// ----------------------------------------------------------------------------
const generateClassFieldByHeader = (mapData: JsonMappingData) => {
  let structConvertFunction = '';
  if (mapData.isOutputStruct) {
    structConvertFunction = `\
  /**
   * @brief Convert struct to class.
   * @param[in] data   struct data.
   */
  void ConvertFromStruct(
      const ${mapData.structType}& data);

  /**
   * @brief Convert class to struct.
   * @return  struct data.
   */
  ${mapData.structType} ConvertToStruct()  const;`;
  }

  const commonFields = `\
  /**
   * @brief Set ignore item.
   * @param[in] key   ignore target key name.
   */
  void SetIgnoreItem(const std::string& key) {
    ignore_items.insert(key);
  }

${structConvertFunction}

 protected:
  /**
   * @brief definition type of Map table.
   */
  using ${mapData.type}MapTable =
    cfd::core::JsonTableMap<${mapData.type}>;

  /**
   * @brief Get JSON mapping object.
   * @return JSON mapping object.
   * @see cfd::core::JsonClassBase::GetJsonMapper()
   */
  virtual const ${mapData.type}MapTable& GetJsonMapper() const {  // NOLINT
    return json_mapper;
  }
  /**
   * @brief Get item lists of JSON mapping.
   * Fetch a list of target variable names in the order of definition.
   * @return Item lists of JSON mapping.
   * @see cfd::core::JsonClassBase::GetJsonItemList()
   */
  virtual const std::vector<std::string>& GetJsonItemList() const {
    return item_list;
  }
  /**
   * @brief Get ignore item lists of JSON mnapping.
   * Ignore the target variable at Serialize.
   * @return Item list of JSON mapping.
   * @see cfd::core::JsonClassBase::GetIgnoreItem()
   */
  virtual const std::set<std::string>& GetIgnoreItem() const {
    return ignore_items;
  }

 private:
 /**
  * @brief JsonFunctionMap table
  */
  static ${mapData.type}MapTable json_mapper;
  /**
   * @brief field name list.
   */
  static std::vector<std::string> item_list;
  /**
   * @brief ignore item list.
   */
  std::set<std::string> ignore_items;
`;
  return commonFields;
};

// ----------------------------------------------------------------------------
// generate header function
// ----------------------------------------------------------------------------
const generateFileHeader = (filename: string, dirname: string, classList: any[],
    jsonSetting: JsonObjectCommonType | undefined, appendHeaderName = '') => {
  const result = [];

  const namespace = (!jsonSetting) ? '' : jsonSetting.namespace;
  const commonHeader = (!jsonSetting) ? '' : jsonSetting.commonHeader;
  let path = `${dirname}/${filename}_`;
  if (path.startsWith(__dirname)) {
    path = path.substr(__dirname.length);
  }
  while (path.indexOf('/', 0) == 0) {
    path = path.substr(1);
  }
  while (path.indexOf('../') >= 0) {
    path = path.replace('../', '');
  }
  while (path.indexOf('./') >= 0) {
    path = path.replace('./', '');
  }
  while (path.indexOf('//') >= 0) {
    path = path.replace('//', '/');
  }
  while (path.indexOf('external/') >= 0) {
    path = path.replace('external/', '');
  }
  while (path.indexOf('/') >= 0) {
    path = path.replace('/', '_');
  }
  while (path.indexOf('.') >= 0) {
    path = path.replace('.', '_');
  }
  while (path.indexOf('-') >= 0) {
    path = path.replace('-', '_');
  }
  const defName = path.toUpperCase();
  const includeHeader = (commonHeader) ? `#include "${commonHeader}"\n` : '';
  const includeHeader2 = (appendHeaderName.length > 0) ? `#include "${appendHeaderName}"\n` : '';

  // header
  const headerFileHeader = `// Copyright 2019 CryptoGarage
/**
 * @file ${filename}
 *
 * @brief JSON mapping file. (auto generate)
 */
#ifndef ${defName}
#define ${defName}

#include <set>
#include <string>
#include <vector>

#include "cfdcore/cfdcore_json_mapping_base.h"
${includeHeader}
${includeHeader2}`;

  result.push(headerFileHeader);

  if (typeof namespace !== 'string') {
    for (let idx = 0; idx < namespace.length; ++idx) {
      result.push(`namespace ${namespace[idx]} {`);
    }
  } else {
    result.push(`namespace ${namespace} {`);
  }

  const headerFileHeader2 = `
using cfd::core::JsonClassBase;
using cfd::core::JsonObjectVector;
using cfd::core::JsonValueVector;
using cfd::core::JsonVector;
// clang-format off
// @formatter:off\
`;

  const headerFileFooter = `
// @formatter:on
// clang-format on
`;
  const headerFileFooter2 = `
#endif  // ${defName}
`;
  result.push(headerFileHeader2);

  if (classList) {
    for (const data in classList) {
      if (!{}.hasOwnProperty.call(classList, data)) continue;
      result.push(classList[data]);
    }
  }

  result.push(headerFileFooter);
  if (typeof namespace !== 'string') {
    for (let idx = namespace.length - 1; idx >= 0; --idx) {
      result.push(`}  // namespace ${namespace[idx]}`);
    }
  } else {
    result.push(`}  // namespace ${namespace}`);
  }
  result.push(headerFileFooter2);
  return result.join('\n');
};

// ----------------------------------------------------------------------------
// generate class header function
// ----------------------------------------------------------------------------
const generateClassHeader = (req: JsonMappingData | null | undefined,
    res: JsonMappingData | null | undefined, jsonSetting: { export: any }) => {
  const result = [];
  const processedList: any[] = [];
  const exportDefine = (jsonSetting.export) ? `${jsonSetting.export} ` : '';

  // header
  if (req || res) {
    const list: JsonMappingData[] = [];
    if (req) list.push(req);
    if (res) list.push(res);
    for (const data of list) {
      if (!data) continue;
      // sort by generate class
      // Child element in order
      const mapList: JsonMappingData[] = [];
      getChildClasses(data, mapList);
      debugLog(`mapList = ${mapList}`);

      for (const mapKey in mapList) {
        if (!{}.hasOwnProperty.call(mapList, mapKey)) continue;
        const mapData = mapList[mapKey];
        if (processedList.includes(mapData.type)) {
          continue;
        }
        const classHeader = generateClassHeaderData(mapData, exportDefine);
        result.push(classHeader);

        for (const childKey in mapData.childList) {
          if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
          const childData = mapData.childList[childKey];
          if (childData.isObject || childData.isArray) {
            const objectFunctions = generateObjectFunctionByHeader(
                mapData, childData);
            result.push(`${objectFunctions}`);
          } else {
            const valueFunctions = generateValueFunctionByHeader(
                mapData, childData);
            result.push(valueFunctions);
          }
        }
        const commonFields = generateClassFieldByHeader(mapData);
        result.push(commonFields);

        for (const childKey in mapData.childList) {
          if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
          const childData = mapData.childList[childKey];
          const objectFields = `\
  /**
   * @brief JsonAPI(${childData.name}) value
   */`;
          result.push(objectFields);
          if (childData.isObject || childData.isArray) {
            result.push(`  ${childData.type} ${childData.variableName}_;  // NOLINT`);
          } else if (childData.type == 'std::string') {
            // string
            result.push(`  ${childData.type} ${childData.variableName}_ = "${childData.initValue}";`);
          } else {
            result.push(`  ${childData.type} ${childData.variableName}_ = ${childData.initValue};`);
          }
        }

        result.push('};');

        processedList.push(mapData.type);
      }
    }
  }

  return result.join('\n');
};


// ----------------------------------------------------------------------------
// generate struct header function
// ----------------------------------------------------------------------------
const generateStructHeaderArea = (mapData: { structType: any }) => {
  const structHeader = `
// ------------------------------------------------------------------------
// ${mapData.structType}
// ------------------------------------------------------------------------
/**
 * @brief ${mapData.structType} struct
 */
struct ${mapData.structType} {`;
  return structHeader;
};

// ----------------------------------------------------------------------------
// generate struct item data function
// ----------------------------------------------------------------------------
const generateStructItemData = (textArray: string[],
    req: JsonMappingData | null | undefined,
    res: JsonMappingData | null | undefined,
    tjsonData: { namespace: string | string[] },
    lastNamespaces: string | any[], hasErrorOutput: boolean,
    processedList: any[], libNamespace: string) => {
  if (req || res) {
    let namespace = '';
    let lastNamespace = '';
    if (typeof tjsonData.namespace === 'string') {
      namespace = tjsonData.namespace;
    } else {
      for (let idx = 0; idx < tjsonData.namespace.length; ++idx) {
        if (namespace.length > 0) {
          namespace += '::' + tjsonData.namespace[idx];
        } else {
          namespace = tjsonData.namespace[idx];
        }
      }
    }
    if (typeof lastNamespaces === 'string') {
      lastNamespace = lastNamespaces;
    } else {
      for (let idx = 0; idx < lastNamespaces.length; ++idx) {
        if (lastNamespace.length > 0) {
          lastNamespace += '::' + lastNamespaces[idx];
        } else {
          lastNamespace = lastNamespaces[idx];
        }
      }
    }

    if (namespace != lastNamespace) {
      if (lastNamespace.length > 0) {
        textArray.push('');
        if (typeof lastNamespaces !== 'string') {
          for (let idx = lastNamespaces.length - 1; idx >= 0; --idx) {
            if (lastNamespaces[idx] != 'json') {
              textArray.push(`}  // namespace ${lastNamespaces[idx]}`);
            }
          }
        } else {
          textArray.push(`}  // namespace ${lastNamespace}`);
        }
        textArray.push('');
      }

      if (typeof tjsonData.namespace !== 'string') {
        for (let idx = 0; idx < tjsonData.namespace.length; ++idx) {
          if (tjsonData.namespace[idx] != 'json') {
            textArray.push(`namespace ${tjsonData.namespace[idx]} {`);
          }
        }
      } else {
        textArray.push(`namespace ${namespace} {`);
      }
    }

    const list: JsonMappingData[] = [];
    if (req) list.push(req);
    if (res) list.push(res);
    for (const data in list) {
      if (!data) continue;
      const mapList: JsonMappingData[] = [];
      getChildClasses(list[data], mapList);

      for (const mapKey in mapList) {
        if (!{}.hasOwnProperty.call(mapList, mapKey)) continue;
        const mapData = mapList[mapKey];
        if (!mapData.isOutputStruct ||
            processedList.includes(mapData.structType)) {
          console.log(`skip output struct: ${mapData.structType}`);
          continue;
        }
        const structHeader = generateStructHeaderArea(mapData);
        textArray.push(structHeader);

        let nameLengthMax = 0;
        for (const childKey in mapData.childList) {
          if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
          const childData = mapData.childList[childKey];
          let nameLength = childData.type.length +
            childData.variableName.length;
          if (childData.isObject || childData.isArray) {
            nameLength = childData.structType.length +
              childData.variableName.length;
          } else if (childData.type == 'std::string') {
            if (typeof childData.initValue === 'string') {
              nameLength += childData.initValue.length + 5;
            }
          } else {
            const stringText = `${childData.initValue}`;
            nameLength += stringText.length + 3;
          }
          if (nameLengthMax < nameLength) nameLengthMax = nameLength;
        }

        for (const childKey in mapData.childList) {
          if (!{}.hasOwnProperty.call(mapData.childList, childKey)) continue;
          const childData = mapData.childList[childKey];
          let nameLength = childData.type.length +
            childData.variableName.length;
          if (childData.isObject || childData.isArray) {
            nameLength = childData.structType.length +
              childData.variableName.length;
          } else if (childData.type == 'std::string') {
            if (typeof childData.initValue === 'string') {
              nameLength += childData.initValue.length + 5;
            }
          } else {
            const stringText = `${childData.initValue}`;
            nameLength += stringText.length + 3;
          }
          let space = '';
          if (nameLengthMax > nameLength) {
            nameLength = nameLengthMax - nameLength;
            for (let i = 0; i < nameLength; ++i) space += ' ';
          }
          const comment = `${space}//!< ${childData.variableName}  // NOLINT`;

          if (childData.isObject || childData.isArray) {
            textArray.push(`  ${childData.structType} ${childData.variableName};  ${comment}`);
          } else if (childData.type == 'std::string') {
            // string
            textArray.push(`  ${childData.type} ${childData.variableName} = "${childData.initValue}";  ${comment}`);
          } else {
            textArray.push(`  ${childData.type} ${childData.variableName} = ${childData.initValue};  ${comment}`);
          }
        }

        if (hasErrorOutput && (mapData.structType.indexOf('ResponseStruct') >= 0)) {
          if (namespace == libNamespace) {
            textArray.push(`  InnerErrorResponseStruct error;       //!< error information`);
          } else {
            textArray.push(`  ${libNamespace}::InnerErrorResponseStruct error;   //!< error information`);
          }
        }
        textArray.push(`  std::set<std::string> ignore_items;   //!< using on JSON mapping convert.`);
        textArray.push('};');

        processedList.push(mapData.structType);
      }
    }
  }
};

// ----------------------------------------------------------------------------
// generate struct header function
// ----------------------------------------------------------------------------
const generateStructHeader = (dirname: string, filename: string,
    jsonList: any[], libNamespace: string) => {
  const result = [];
  const processedStructTypes: never[] = [];

  let path = `${dirname}/${filename}_`;
  if (path.startsWith(__dirname)) {
    path = path.substr(__dirname.length);
  }
  while (path.indexOf('/', 0) == 0) {
    path = path.substr(1);
  }
  while (path.indexOf('../') >= 0) {
    path = path.replace('../', '');
  }
  while (path.indexOf('./') >= 0) {
    path = path.replace('./', '');
  }
  while (path.indexOf('//') >= 0) {
    path = path.replace('//', '/');
  }
  while (path.indexOf('external/') >= 0) {
    path = path.replace('external/', '');
  }
  while (path.indexOf('/') >= 0) {
    path = path.replace('/', '_');
  }
  while (path.indexOf('.') >= 0) {
    path = path.replace('.', '_');
  }
  while (path.indexOf('-') >= 0) {
    path = path.replace('-', '_');
  }
  const defName = path.toUpperCase();

  // header
  const headerFileHeader = `// Copyright 2019 CryptoGarage
/**
 * @file ${filename}
 *
 * @brief Struct mapping file. (auto generate)
 */
#ifndef ${defName}
#define ${defName}

#include <cstdint>
#include <set>
#include <string>
#include <vector>

// clang-format off
// @formatter:off\
`;
  const headerFileFooter = `
// @formatter:on
// clang-format on

#endif  // ${defName}
`;
  result.push(headerFileHeader);

  let lastNamespace = '';
  for (const jsonDataIndex in jsonList) {
    if (!{}.hasOwnProperty.call(jsonList, jsonDataIndex)) continue;
    if (('priority' in jsonList[jsonDataIndex].tjsonData) &&
      (jsonList[jsonDataIndex].tjsonData['priority'] == 'high')) {
      const req = jsonList[jsonDataIndex].requestData;
      const res = jsonList[jsonDataIndex].responseData;
      generateStructItemData(result, req, res,
          jsonList[jsonDataIndex].tjsonData, lastNamespace, false,
          processedStructTypes, libNamespace);
      lastNamespace = jsonList[jsonDataIndex].tjsonData.namespace;
    }
  }

  for (const jsonDataIndex in jsonList) {
    if (!{}.hasOwnProperty.call(jsonList, jsonDataIndex)) continue;
    if (('priority' in jsonList[jsonDataIndex].tjsonData) &&
      (jsonList[jsonDataIndex].tjsonData['priority'] == 'high')) {
      // do nothing
    } else {
      const req = jsonList[jsonDataIndex].requestData;
      const res = jsonList[jsonDataIndex].responseData;
      generateStructItemData(result, req, res,
          jsonList[jsonDataIndex].tjsonData, lastNamespace, true,
          processedStructTypes, libNamespace);
      // const tjsonData = jsonList[jsonDataIndex].tjsonData;
      lastNamespace = jsonList[jsonDataIndex].tjsonData.namespace;
    }
  }
  result.push('');
  if (isArray(lastNamespace)) {
    for (let idx = lastNamespace.length - 1; idx >= 0; --idx) {
      if (lastNamespace[idx] != 'json') {
        result.push(`}  // namespace ${lastNamespace[idx]}`);
      }
    }
  } else {
    result.push(`}  // namespace ${lastNamespace}`);
  }

  result.push(headerFileFooter);
  return result.join('\n');
};


// ----------------------------------------------------------------------------
// generate typescript data file function
// ----------------------------------------------------------------------------
const generateTsData = (dirname: string, filename: string,
    jsonClassMap: ClassMapType, jsonTypeList: any[],
    functionList: string | any[], loadCfdjsIndexFile: fs.PathLike,
    promiseMode: boolean, tsClassName: string,
    insertFunctions: TsAppendFunctionData[],
    insertErrorFunctions: TsAppendFunctionData[]) => {
  let outPath = `${dirname}/${filename}`;
  if (outPath.startsWith(__dirname)) {
    outPath = outPath.substr(__dirname.length);
  }
  while (outPath.indexOf('/', 0) == 0) {
    outPath = outPath.substr(1);
  }
  while (outPath.indexOf('//') >= 0) {
    outPath = outPath.replace('//', '/');
  }

  // initialize
  const project = new Project({
    tsConfigFilePath: `${__dirname}/../tsconfig.json`,
    addFilesFromTsConfig: false,
  });

  if (loadCfdjsIndexFile) {
    fs.copyFileSync(loadCfdjsIndexFile, outPath);
  }

  // add source files
  const file = (!loadCfdjsIndexFile) ? project.createSourceFile(outPath, '\n') :
      project.addSourceFileAtPath(outPath);

  if (loadCfdjsIndexFile) {
    const internalErrorObj = file.getInterface('InnerErrorResponse');
    if (internalErrorObj !== undefined) {
      internalErrorObj.remove();
    }
    const errorObj = file.getInterface('ErrorResponse');
    if (errorObj !== undefined) {
      errorObj.remove();
    }
  } else {
    file.insertStatements(0, '/* eslint-disable max-len */');
    file.insertStatements(1, '/* eslint-disable require-jsdoc */');
  }

  for (let i = 0; i < jsonTypeList.length; ++i) {
    const clsName = jsonTypeList[i];
    const props = jsonClassMap[clsName];
    debugLog(`${clsName} = `, props);
    file.addInterface({
      name: clsName,
      isExported: true,
      properties: props,
    });
  }

  let classObj = undefined;
  if (tsClassName !== '') {
    classObj = file.addClass({
      name: tsClassName,
      isExported: true,
    });
  }

  for (let i = 0; i < functionList.length; ++i) {
    // manipulate
    const funcName = functionList[i];
    const reqName = `${funcName}Request`;
    const resName = `${funcName}Response`;
    const resDataName = (promiseMode) ? `Promise<${resName}>` : resName;
    const params = (reqName in jsonClassMap) ? [{name: 'jsonObject', type: reqName}] : [];
    const retType = (resName in jsonClassMap) ? resDataName : undefined;
    if (classObj === undefined) {
      file.addFunction({
        name: funcName,
        isExported: true,
        parameters: params,
        returnType: retType,
      });
    } else {
      classObj.addMethod({
        name: funcName,
        parameters: params,
        returnType: retType,
      });
    }
  }

  for (let i = 0; i < insertFunctions.length; ++i) {
    const funcName = insertFunctions[i].name;
    const params = insertFunctions[i].parameters;
    const retType = insertFunctions[i].returnType;
    file.addFunction({
      name: funcName,
      isExported: true,
      parameters: params,
      returnType: retType,
    });
  }

  const errorClassObj = file.addClass({
    name: 'CfdError',
    isExported: true,
  });
  errorClassObj.setExtends('Error');
  for (let i = 0; i < insertErrorFunctions.length; ++i) {
    const funcName = insertErrorFunctions[i].name;
    const params = insertErrorFunctions[i].parameters;
    const retType = insertErrorFunctions[i].returnType;
    if (funcName == 'constructor') {
      errorClassObj.addConstructor({
        parameters: params,
        returnType: retType,
      });
    } else {
      errorClassObj.addMethod({
        name: funcName,
        parameters: params,
        returnType: retType,
      });
    }
  }

  // asynchronously save all the changes above
  project.save().then(() => console.log(`output: ${outPath}`));
};


// ----------------------------------------------------------------------------
// search file
// ----------------------------------------------------------------------------
function convertFile() {
  // const fileList = [];
  let cfdBaseDir: string;
  const libname = 'cfd-js';
  const libPrefix = 'cfdjs';
  const libNamespace = 'cfd::js::api';
  const cfdPath = `${__dirname}/../external/${libname}/`;
  const cfdPath2 = `${__dirname}/../../${libname}/`;
  let folderPath = `src/input_json_format/`;
  const outJsonSourceFolderPath = `${__dirname}/../../${libname}/src/autogen/`;
  const outJsonHeaderFolderPath = `${__dirname}/../../${libname}/src/autogen/`;
  let outStructDirPath = `include/${libPrefix}/`;
  const loadCfdjsIndexFile = '';
  let outTsFolderPath = ``;
  const outStructFileName = `${libPrefix}_struct.h`;
  const outTsFileName = `index.d.ts`;
  const classHeaderList: string[] = [];
  const classSourceList: string[] = [];
  const jsonDataList: JsonData[] = [];
  let jsonClassMap: ClassMapType = {};
  let jsonTypeList: any[] = [];
  const functionList: string[] = [];
  const promiseMode = false;
  const tsClassName = '';
  const insertFunctions: TsAppendFunctionData[] = [];
  const insertErrorFunctions: TsAppendFunctionData[] = [{
    name: 'constructor',
    parameters: [{
      name: 'message',
      type: 'string',
    }, {
      name: 'errorInformation',
      type: 'InnerErrorResponse',
    }, {
      name: 'cause',
      type: 'Error',
    }],
    returnType: 'void',
  }, {
    name: 'toString',
    parameters: [],
    returnType: 'string',
  }, {
    name: 'getErrorInformation',
    parameters: [],
    returnType: 'InnerErrorResponse',
  }, {
    name: 'getCause',
    parameters: [],
    returnType: 'Error',
  }];

  if (fs.existsSync(cfdPath) && fs.statSync(cfdPath).isDirectory()) {
    cfdBaseDir = cfdPath;
    outTsFolderPath = cfdPath + outTsFolderPath;
    folderPath = cfdPath + folderPath;
    outStructDirPath = cfdPath + outStructDirPath;
  } else {
    cfdBaseDir = cfdPath2;
    outTsFolderPath = `${__dirname}/`; // relative path from tsconfig.json
    folderPath = cfdPath2 + folderPath;
    outStructDirPath = cfdPath2 + outStructDirPath;
  }

  let jsonObjectCommon: JsonObjectCommonType | undefined = undefined;
  fs.readdir(folderPath, (err, files) => {
    if (err) throw err;
    files.filter(function(file) {
      // filter
      return fs.statSync(`${folderPath}${file}`).isFile() && /.*\.json$/.test(file);
    }).forEach(function(file) {
      console.log(`file = ${file}`);
      const inFile = `${folderPath}${file}`;
      // const outFile = file.replace(/\.json$/i, '_json');
      // const outHeaderFile = `${outFile}.h`;
      // const outSourceFile = `${outFile}.cpp`;

      // read json
      const jsonObject = JSON.parse(fs.readFileSync(inFile, 'utf8'));
      const reqData = (jsonObject.request) ? analyzeJson(jsonObject.request, 'root') : null;
      const resData = (jsonObject.response) ? analyzeJson(jsonObject.response, 'root') : null;
      let funcName = '';
      if (reqData != null) {
        const ret = reqData.collectMapData(jsonClassMap, jsonTypeList, true);
        jsonClassMap = ret['map'];
        jsonTypeList = ret['list'];
        funcName = reqData.getFunctionName();
      }
      if (resData != null) {
        const ret = resData.collectMapData(jsonClassMap, jsonTypeList, false);
        jsonClassMap = ret['map'];
        jsonTypeList = ret['list'];
        if (funcName === '') funcName = resData.getFunctionName();
      }
      if (funcName !== '') functionList.push(funcName);
      debugLog(`reqData = ${reqData}`);
      debugLog(`resData = ${resData}`);
      jsonDataList.push(new JsonData(jsonObject, reqData, resData));

      const headerStr = generateClassHeader(reqData, resData, jsonObject);
      classHeaderList.push(headerStr);
      const srcStr = generateClassSource(reqData, resData);
      classSourceList.push(srcStr);
      if (jsonObjectCommon === undefined) {
        jsonObjectCommon = jsonObject;
      } else {
        if (jsonObject.namespace && jsonObject.namespace.length > 0) {
          jsonObjectCommon['namespace'] = jsonObject.namespace;
        }
        if (jsonObject.commonHeader && jsonObject.commonHeader.length > 0) {
          jsonObjectCommon['commonHeader'] = jsonObject.commonHeader;
        }
      }
    });

    {
      let srnamespaceName = '';
      const namespace = (jsonObjectCommon) ? jsonObjectCommon.namespace : '';
      if (typeof namespace !== 'string') {
        for (let idx = 0; idx < namespace.length; ++idx) {
          if (idx !== 0) srnamespaceName += '_';
          srnamespaceName += namespace[idx];
        }
      } else {
        srnamespaceName += namespace;
      }

      if (outStructFileName !== '') {
        const outHeaderFile = `${srnamespaceName}_autogen.h`;
        const outSourceFile = `${srnamespaceName}_autogen.cpp`;
        const headerStr = generateFileHeader(outHeaderFile,
            outJsonHeaderFolderPath,
            classHeaderList, jsonObjectCommon, `${libPrefix}/${outStructFileName}`);
        fs.writeFileSync(`${outJsonHeaderFolderPath}${outHeaderFile}`, headerStr);
        const srcStr = generateFileSource(outSourceFile,
            outHeaderFile, classSourceList, jsonObjectCommon);
        fs.writeFileSync(`${outJsonSourceFolderPath}${outSourceFile}`, srcStr);
      }
    };

    if ((jsonDataList.length > 0) && (outStructFileName !== '')) {
      const headerStr = generateStructHeader(outStructDirPath,
          outStructFileName, jsonDataList, libNamespace);
      fs.writeFileSync(path.resolve(`${outStructDirPath}${outStructFileName}`), headerStr);
      console.log(`output: ${outStructFileName}`);
    }

    if (jsonTypeList.length > 0) {
      try {
        fs.unlinkSync(path.resolve(`${cfdBaseDir}${outTsFileName}`));
      } catch (err) {
        // do nothing
      }
      generateTsData(outTsFolderPath, outTsFileName, jsonClassMap,
          jsonTypeList, functionList, loadCfdjsIndexFile, promiseMode,
          tsClassName, insertFunctions, insertErrorFunctions);
    }
  });
};


const main = function() {
  for (let i = 2; i < process.argv.length; i++) {
    if (process.argv[i]) {
      if (process.argv[i] === 'mode=debug') {
        debugLog = function(...args: any | any[]) {
          if (!isArray(args)) {
            console.log(args);
            return;
          }
          switch (args.length) {
            case 1:
              console.log(args[0]);
              break;
            case 2:
              console.log(args[0], args[1]);
              break;
            case 3:
              console.log(args[0], args[1], args[2]);
              break;
            default:
              console.log(Array.prototype.join.call(args));
              break;
          }
        };
      }
    }
  }

  convertFile();
};
main();
