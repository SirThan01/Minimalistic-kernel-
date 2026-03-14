#include "kernel_stdio.h"
#define VIDEO 0xB8000
#define ATTR 0x07
keyboard_init();
i8254_init();
void kernel_main() {
    print("hello user!\n")
    print("welcome to minimal kernel\n");
    print("kernel made in one day!\n");
    print("x86 architecture\n");
    print("made by me\n");
    print("0x1icdx01x1");
    
    keyboard_init();
    i8254_init();
    while(1);
}
