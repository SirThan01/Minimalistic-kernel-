#include "kernel_stdio.h"
#define VIDEO 0xB8000
#define ATTR 0x07
keyboard_init();
i8254_init();
void kernel_main() {
    char *video = (char*)VIDEO;
    *video++ = 'K'; *video++ = ATTR;
    *video++ = 'E'; *video++ = ATTR;
    *video++ = 'R'; *video++ = ATTR;
    *video++ = 'N'; *video++ = ATTR;
    *video++ = 'E'; *video++ = ATTR;
    *video++ = 'L'; *video++ = ATTR;
    *video++ = ' '; *video++ = ATTR;
    *video++ = 'I'; *video++ = ATTR;
    *video++ = 'N'; *video++ = ATTR;
    *video++ = 'F'; *video++ = ATTR;
    *video++ = 'O'; *video++ = ATTR;
    *video++ = '\n'; *video++ = ATTR;
    *video++ = 0xE2; *video++ = ATTR;
    *video++ = 0x94; *video++ = ATTR;
    *video++ = 0x94; *video++ = ATTR;
    *video++ = 0xE2; *video++ = ATTR;
    *video++ = 0x94; *video++ = ATTR;
    *video++ = 0x80; *video++ = ATTR;
    *video++ = ' '; *video++ = ATTR;
    *video++ = 'A'; *video++ = ATTR;
    *video++ = 'r'; *video++ = ATTR;
    *video++ = 'c'; *video++ = ATTR;
    *video++ = 'h'; *video++ = ATTR;
    *video++ = 'i'; *video++ = ATTR;
    *video++ = 't'; *video++ = ATTR;
    *video++ = 'e'; *video++ = ATTR;
    *video++ = 'c'; *video++ = ATTR;
    *video++ = 't'; *video++ = ATTR;
    *video++ = 'u'; *video++ = ATTR;
    *video++ = 'r'; *video++ = ATTR;
    *video++ = 'e'; *video++ = ATTR;
    *video++ = ':'; *video++ = ATTR;
    *video++ = ' '; *video++ = ATTR;
    *video++ = 'x'; *video++ = ATTR;
    *video++ = '8'; *video++ = ATTR;
    *video++ = '6'; *video++ = ATTR;
    *video++ = '\n'; *video++ = ATTR;
    while(1);
}
