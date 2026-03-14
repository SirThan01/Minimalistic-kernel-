#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <stdint.h>
void keyboard_install(uint8_t idt_irq_number, void (*char_callback)(char));
char keyboard_getchar_nonblocking(void);
char keyboard_getchar_blocking(void);
#endif
