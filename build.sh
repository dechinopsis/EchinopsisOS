nasm -f elf32 ./src/koa.asm -o ./bin/kasm.o
gcc -m32 -c ./src/koa.c -o ./bin/kc.o -ffreestanding
gcc -m32 -c ./src/include/system.c -o ./bin/obj/system.o -ffreestanding
gcc -m32 -c ./src/include/string.c -o ./bin/obj/string.o -ffreestanding
gcc -m32 -c ./src/include/screen.c -o ./bin/obj/screen.o -ffreestanding
gcc -m32 -c ./src/include/kb.c -o ./bin/obj/kb.o -ffreestanding
ld -m elf_i386 -T ./src/link.ld -o ./bin/koa.bin ./bin/kasm.o ./bin/kc.o ./bin/obj/system.o ./bin/obj/string.o ./bin/obj/screen.o ./bin/obj/kb.o
qemu-system-i386 -kernel ./bin/koa.bin 

read a
