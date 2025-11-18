@echo off
REM Build script for QuarkBIOS

REM Assemble the bootloader
nasm -f bin ..\src\boot.asm -o ..\build\boot.bin

if %errorlevel% neq 0 (
    echo Assembly failed!
    exit /b %errorlevel%
)

echo Build successful! Output: ..\build\boot.bin