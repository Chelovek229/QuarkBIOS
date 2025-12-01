/*
 * QuarkBIOS
 * Copyright (C) 2025 KiG Organizatio
 *
 * This file is part of QuarkBIOS.
 *
 * QuarkBIOS is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * QuarkBIOS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with QuarkBIOS.  If not, see <http://www.gnu.org/licenses/>.
 */


// mouse.c - Mouse handling for QuarkBIOS

#include "bios.h"

void init_mouse() {
    // Initialize mouse
    asm volatile (
        "mov $0x00, %%ax\n"
        "int $0x33\n"
        :
        :
        : "ax"
    );
}

void get_mouse_position(int* x, int* y) {
    // Get mouse position
    asm volatile (
        "mov $0x03, %%ax\n"
        "int $0x33\n"
        : "=c"(*x), "=d"(*y)
        :
        : "ax"
    );

}

