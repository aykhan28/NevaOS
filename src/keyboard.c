#define KEYBOARD_PORT 0x60 // Keyboard data port
#define STATUS_PORT  0x64  // Keyboard status port
#define BACKSPACE 0x0E

#include "keyboard.h"

static inline unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__ __volatile__ ("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

unsigned char keymap[128] = {
    0,  27, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=', '\b',
    '\t', 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\n',
    0, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`', 0,
    '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0, '*',
    0, ' ', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '-', 0, 0, 0, '+',
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

char k_getchar() {
    unsigned char scancode;

    while (!(inb(STATUS_PORT) & 1)); // Klavyeden veri bekle
    scancode = inb(KEYBOARD_PORT);

    if (scancode & 0x80) {
        return 0; // Tuş bırakıldıysa bir şey yapma
    } else if (scancode == BACKSPACE) {
        return BACKSPACE;
    } else {
        return keymap[scancode]; // Scan kodunu ASCII'ye çevir
    }
}