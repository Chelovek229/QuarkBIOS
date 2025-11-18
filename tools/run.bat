@echo off
REM Run script for QuarkBIOS

REM Check if QEMU is installed
where qemu-system-x86 >nul 2>nul
if %errorlevel% neq 0 (
    echo QEMU not found! Please install QEMU and add it to your PATH.
    exit /b %errorlevel%
)

REM Run the BIOS in QEMU
qemu-system-x86 -drive format=raw,file=..\build\boot.bin -boot a