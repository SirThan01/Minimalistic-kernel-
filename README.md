# Minimalistic-kernel
The assembler code is not mine.
Minimal kernel in C + assembly 

# Compilation

nasm -f elf32 start.asm -o start.o
gcc -ffreestanding -m32 -nostdlib -nostartfiles -fno-pie -c kernel.c -o kernel.o
ld -m elf_i386 -T linker.ld -o kernel.bin start.o kernel.o
qemu-system-i386 -kernel kernel.bin

# MAKEFILE

nasm -f elf32 start.asm -o start.o
gcc -ffreestanding -m32 -nostdlib -nostartfiles -fno-pie -c kernel.c -o kernel.o ld -m elf_i386 -T linker.ld -o kernel.bin start.o kernel.o

# Usage 

Understanding how the kernel works.
Understanding protected mode.
Base for kernel experiments.

# Info
This is a newbie project.
Architecture x86.

