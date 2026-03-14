# Minimalistic-kernel
The assembler code is not mine!
Minimal kernel in C and assembly.

# Compilation
nasm -f elf32 start.asm -o start.o
gcc -ffreestanding -m32 -nostdlib -nostartfiles -fno-pie -c kernel.c -o kernel.o
ld -m elf_i386 -T linker.ld -o kernel.bin start.o kernel.o
qemu-system-i386 -kernel kernel.bin

# MAKEFILE
all: kernel.bin
start.o: start.asm
	nasm -f elf32 start.asm -o start.o
kernel.o: kernel.c
	gcc -ffreestanding -m32 -nostdlib -nostartfiles -fno-pie -c kernel.c -o kernel.o
kernel.bin: start.o kernel.o
	ld -m elf_i386 -T linker.ld -o kernel.bin start.o kernel.o
run: kernel.bin
	qemu-system-i386 -kernel kernel.bin
clean:
	rm -f *.o *.bin

# Usage
Understanding how the kernel works. Understanding protected mode. Base for kernel experiments.

# Info
This is a newbie project. Architecture x86.

# Important
This is not an .exe file you can't open it with a mouse click!
What to do if you want to run it:
1. Install QEMY or VirtualBox
2. Read the "Compilation" section
3. Be patient
Also, if you're looking for a Windows game, you've come to the wrong door.
