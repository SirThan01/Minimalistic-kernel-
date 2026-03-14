#ifndef KERNEL_PRINT_H
#define KERNEL_PRINT_H
#include <stdint.h>
#ifndef VIDEO
#define VIDEO 0xB8000
#endif
#ifndef ATTR
#define ATTR 0x07
#endif
#define KSCR_WIDTH 80
#define KSCR_HEIGHT 25
#define KSCR_BYTES (KSCR_WIDTH * KSCR_HEIGHT * 2)
static volatile unsigned int k_pos_print = 0;
static inline void k_putc_print(char c) {
    volatile unsigned char *video = (volatile unsigned char*)(uintptr_t)VIDEO;
    if (c == '\n') {
        unsigned int row = k_pos_print / (KSCR_WIDTH * 2);
        row++;
        k_pos_print = row * KSCR_WIDTH * 2;
        if (k_pos_print >= KSCR_BYTES) k_pos_print = 0;
        return;
    }
    if (k_pos_print >= KSCR_BYTES) k_pos_print = 0;
    video[k_pos_print++] = (unsigned char)c;
    video[k_pos_print++] = (unsigned char)ATTR;
}
static inline void print(const char *s) {
    if (!s) return;
    while (*s) {
        k_putc_print(*s++);
    }
}
#endif
