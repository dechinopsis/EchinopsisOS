nasm -f elf32 ./src/koa.asm -o ./bin/kasm.o
gcc -m32 -c ./src/koa.c -o ./bin/kc.o
ld -m elf_i386 -T ./src/link.ld -o ./bin/koa.bin ./bin/kasm.o ./bin/kc.o
qemu-system-i386 -kernel ./bin/koa.bin 

read a
