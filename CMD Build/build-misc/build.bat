@echo off

mkdir ..\build
pushd ..\build
cl -Zi ..\src\win32_lhmh.cpp user32.lib gdi32.lib
popd