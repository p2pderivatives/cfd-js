@echo off
setlocal

set lint_ecode=""
cd ..
call :search_lint include\cfdjs ..\..
call :search_lint src ..
call :search_lint src\autogen ..\..

if %lint_ecode% == "1" (
    exit 1
)
exit /b

:search_lint
cd %1
for %%A in (*.h) do (
    call :exec_lint %2\tools\cpplint\cpplint.py %%A
)
for %%A in (*.cpp) do (
    call :exec_lint %2\tools\cpplint\cpplint.py %%A
)
cd %2
exit /b

:exec_lint
python %1 --quiet %2
if not %ERRORLEVEL% == 0 (
    set lint_ecode="1"
)
exit /b
