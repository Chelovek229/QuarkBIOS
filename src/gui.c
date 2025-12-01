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


// gui.c - Graphical User Interface for QuarkBIOS

#include "bios.h"

void init_gui() {
    // Initialize VGA graphics mode
    set_vga_mode(0x13); // 320x200, 256 colors
    draw_background(2); // Green background
    draw_text(10, 10, "QuarkBIOS GUI Initialized", 15); // White text
}

void draw_background(int color) {
    // Fill the screen with the specified color
    unsigned char* vga = (unsigned char*)0xA0000;
    for (int i = 0; i < 320 * 200; i++) {
        vga[i] = color;
    }
}

void draw_text(int x, int y, const char* text, int color) {
    // Draw text at the specified position
    unsigned char* vga = (unsigned char*)0xA0000;
    while (*text) {
        int offset = (y * 320) + x;
        vga[offset] = color;
        text++;
        x += 8; // Move to the next character position
    }

}

