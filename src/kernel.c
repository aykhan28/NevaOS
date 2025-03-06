#define WHITE_TXT 0x07
#define BACKSPACE 0x0E

#include "kernel.h"
#include "terminal.h"
#include "io.h"
#include "keyboard.h"
#include <stdarg.h>

void k_printf(const char *format, ...);
void k_putchar(char c);
void k_puts(const char *str);

void k_main() {
    k_clear_screen();
    k_printf("White %s, %c, %i, %x \n", "Cloud", 'b', 22, 10);
    k_terminal();
}

void k_clear_screen() {
    char *vidmem = (char *) 0xb8000;
    unsigned int i = 0;
    while (i < (80 * 25 * 2)) {
        vidmem[i] = ' ';
        i++;
        vidmem[i] = WHITE_TXT;
        i++;
    };
}

void k_printf(const char *format, ...) {
    char buffer[32];
    char *str;
    int i;

    va_list args;
    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'i':  // Integer
                    itoa(va_arg(args, int), buffer, 10);
                    k_puts(buffer);
                    break;
                case 'x':  // Hexadecimal
                    itoa(va_arg(args, int), buffer, 16);
                    k_puts(buffer);
                    break;
                case 's':  // String ""
                    str = va_arg(args, char*);
                    k_puts(str);
                    break;
                case 'c':  // Char ''
                    k_putchar((char) va_arg(args, int));
                    break;
                default:
                    k_putchar('%');
                    k_putchar(*format);
            }
        } else {
            k_putchar(*format);
        }
        format++;
    }

    va_end(args);
}