#include "keyboard.h"
#include "keymap.h"
#include <stdint.h>
#include <stddef.h>
extern uint8_t inb(uint16_t port);
extern void register_interrupt_handler(uint8_t idt_index, void (*handler)(void));
extern void pic_send_eoi(uint8_t irq);
#define KBD_DATA_PORT 0x60
#define KBD_IRQ       1
#define KBD_BUF_SIZE 256
static volatile char kbd_buf[KBD_BUF_SIZE];
static volatile size_t kbd_head = 0; 
static volatile size_t kbd_tail = 0;
static void (*user_callback)(char) = NULL;
static volatile int shift_count = 0;
#define SC_LSHIFT 0x2A
#define SC_RSHIFT 0x36
#define SC_ENTER  0x1C
#define SC_BACKSP 0x0E
#define SC_SPACE  0x39
static inline void kbd_push(char c) {
    size_t next = (kbd_head + 1) % KBD_BUF_SIZE;
    if (next == kbd_tail) {
        return;
    }
    kbd_buf[kbd_head] = c;
    kbd_head = next;
}
char keyboard_getchar_nonblocking(void) {
    if (kbd_head == kbd_tail) return 0;
    char c = kbd_buf[kbd_tail];
    kbd_tail = (kbd_tail + 1) % KBD_BUF_SIZE;
    return c;
}
char keyboard_getchar_blocking(void) {
    char c;
    while ((c = keyboard_getchar_nonblocking()) == 0) {
    }
    return c;
}
static void keyboard_irq_handler(void) {
    uint8_t sc = inb(KBD_DATA_PORT);
    if (sc & 0x80) {
        uint8_t make_sc = sc & 0x7F;
        if (make_sc == SC_LSHIFT || make_sc == SC_RSHIFT) {
            if (shift_count > 0) shift_count--;
        }
        pic_send_eoi(KBD_IRQ);
        return;
    }
    if (sc == SC_LSHIFT || sc == SC_RSHIFT) {
        shift_count++;
        pic_send_eoi(KBD_IRQ);
        return;
    }
    char c = 0;
    if (sc == SC_ENTER) {
        c = '\n';
    } else if (sc == SC_BACKSP) {
        c = '\b';
    } else if (sc == SC_SPACE) {
        c = ' ';
    } else if (sc < 128) {
        if (shift_count)
            c = keymap_upper[sc];
        else
            c = keymap_lower[sc];
    }
    if (c) {
        kbd_push(c);
        if (user_callback) user_callback(c);
    }
    pic_send_eoi(KBD_IRQ);
}
void keyboard_install(uint8_t idt_irq_number, void (*char_callback)(char)) {
    user_callback = char_callback;
    register_interrupt_handler(idt_irq_number, keyboard_irq_handler);
}
