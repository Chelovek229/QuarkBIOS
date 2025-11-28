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


// bios.h - Common definitions for QuarkBIOS

#ifndef BIOS_H
#define BIOS_H

void init_gui();
void draw_background(int color);
void draw_text(int x, int y, const char* text, int color);

void init_keyboard();
char get_key();

void init_mouse();
void get_mouse_position(int* x, int* y);

void read_sector(int drive, int sector, void* buffer);


#endif // BIOS_H
