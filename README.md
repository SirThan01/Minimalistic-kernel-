# Minimalistic-kernel
The assembler code is not mine!
Minimal kernel in C and assembly.

## MAKEFILE
```
CC = i686-elf-gcc
AS = nasm
LD = i686-elf-ld
CFLAGS = -m32 -ffreestanding -O2 -Wall -Wextra -I.
ASFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T linker.ld
C_SOURCES = $(shell find . -name "*.c")
OBJ = ${C_SOURCES:.c=.o} boot.o
all: kernel-001
kernel-001: ${OBJ}
	${LD} ${LDFLAGS} -o $@ $^
%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
boot.o: boot.asm
	${AS} ${ASFLAGS} boot.asm -o boot.o
clean:
	rm -rf *.o kernel-001
	find . -name "*.o" -type f -delete

```
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
