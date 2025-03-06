#ifndef KERNEL_H
#define KERNEL_H

void k_clear_screen();
void k_printf(const char *format, ...);
void k_puts(const char *str);
void k_putchar(char c);
void itoa(int num, char *str, int base);
void k_terminal();
void keyboard_init();

#endif
