/*
 * This file is part of the QuarkBIOS project.
 *
 * Copyright (C) 2025 KiG Organization
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

@echo off
REM Build script for QuarkBIOS

REM Assemble the bootloader
nasm -f bin ..\src\boot.asm -o ..\build\boot.bin

if %errorlevel% neq 0 (
    echo Assembly failed!
    exit /b %errorlevel%
)


echo Build successful! Output: ..\build\boot.bin
