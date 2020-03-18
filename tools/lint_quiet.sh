#!/bin/bash

lint_ecode=0

function search_lint() {
    cd $2
    for file in `\find . -maxdepth 1 -name '*.h'`; do
        $1 $3/tools/cpplint/cpplint.py --quiet $file > /dev/null
        if [ $? -gt 0 ]; then
            lint_ecode=1
        fi
    done
    for file in `\find . -maxdepth 1 -name '*.cpp'`; do
        $1 $3/tools/cpplint/cpplint.py --quiet $file > /dev/null
        if [ $? -gt 0 ]; then
            lint_ecode=1
        fi
    done
    cd $3
}

py_exe="python"
if [ `which python3` ]; then
  py_exe="python3"
fi

cd `git rev-parse --show-toplevel`
search_lint $py_exe include/cfdjs ../..
search_lint $py_exe src ..
search_lint $py_exe src/autogen ../..

if [ $lint_ecode -gt 0 ]; then
    exit 1
fi
