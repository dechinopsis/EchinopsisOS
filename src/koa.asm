bits 32
section		.text
	align	4
	dd	0x1BADB002
	dd	0x00
	dd	- (0x1BADB002+0x00)

global start
extern kmain		;this function is located in koa.c
start:
	cli		;clears the interrupts
	call kmain	;sen processor to coninue execution from kmain.c
	hlt		;halt the cpu(pause it from executinf from this address)
