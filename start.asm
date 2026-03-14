bits 32
section .text
global start
extern kernel_main

start:
    mov esp, stack_top
    call kernel_main
    hlt

section .bss
resb 8192
stack_top:
