CC = gcc
AS = nasm
LD = ld
CFLAGS = -m32 -fno-stack-protector -nostdlib
LDFLAGS = -m elf_i386 -T linker.ld

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
ASM = src/kernel.asm
ASM_OBJ = kernel.o

all: build/kernel.bin

build/kernel.bin: $(OBJ) $(ASM_OBJ)
	$(LD) $(LDFLAGS) -o build/kernel.bin $(OBJ) $(ASM_OBJ)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

src/kernel.o: src/kernel.asm
	$(AS) -f elf32 -o src/kernel.o src/kernel.asm

clean:
	rm -f build/*.o build/kernel.bin