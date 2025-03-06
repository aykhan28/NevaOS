#define BACKSPACE 0x0E
#define WHITE_TXT 0x07

#include "io.h"

void k_putchar(char c) {
    static char *vidmem = (char*) 0xb8000;
    static unsigned int i = 0;

    if (c == BACKSPACE) {
        if (i > 0) {
            i -= 2;
            vidmem[i] = ' ';
            vidmem[i + 1] = WHITE_TXT;
        }
        return;
    }

    if (c == '\n') {
        i = (i / (80 * 2) + 1) * 80 * 2;
    } else {
        vidmem[i++] = c;
        vidmem[i++] = WHITE_TXT;
    }
}

void k_puts(const char *str) {
    while (*str) {
        k_putchar(*str++);
    }
}
