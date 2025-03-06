#define BACKSPACE 0x0E

#include "terminal.h"
#include "io.h"
#include "keyboard.h"
#include "kernel.h"

void k_terminal() {
    char buffer[256];
    int index = 0;

    k_printf(">> ");

    while (1) {
        char c = k_getchar();

        if (c == '\n') {
            buffer[index] = '\0';
            if (buffer[0] == 'w' && buffer[1] == 'r' && buffer[2] == 'i' && buffer[3] == 't' && buffer[4] == 'e' && buffer[5] == ' ') {
                k_printf("\n %s :)", &buffer[6]);
            }
            index = 0;
            k_printf("\n>> ");
        } else if (c == BACKSPACE && index > 0) {
            index--;
            k_putchar(BACKSPACE);
        } else if (c >= 32 && c <= 126) {
            buffer[index++] = c;
            k_putchar(c);
        }
    }
}
