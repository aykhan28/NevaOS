echo "Cleaning..."
rm -f src/*.o kernel.bin

echo ".asm -> .o ..."
nasm -f elf32 src/kernel.asm -o src/kasm.o

echo ".c -> .o ..."
gcc -m32 -c -fno-stack-protector -I./include src/kernel.c -o src/kc.o
gcc -m32 -c -fno-stack-protector -I./include src/terminal.c -o src/terminal.o
gcc -m32 -c -fno-stack-protector -I./include src/io.c -o src/io.o
gcc -m32 -c -fno-stack-protector -I./include src/utils.c -o src/utils.o
gcc -m32 -c -fno-stack-protector -I./include src/keyboard.c -o src/keyboard.o

echo "Linking is staring"
ld -m elf_i386 -T link.ld -o kernel.bin src/kasm.o src/kc.o src/terminal.o src/io.o src/utils.o src/keyboard.o

echo "Finished"
