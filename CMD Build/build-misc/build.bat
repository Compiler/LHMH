@echo off

mkdir ..\build
pushd ..\build
cl -Zi ..\src\win32_lhmh.cpp
popd