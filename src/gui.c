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