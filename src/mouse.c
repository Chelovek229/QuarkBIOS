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