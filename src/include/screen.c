#include "screen.h"
int cursorX = 0;
int cursorY = 0;
const uint8 sw = 80;
const uint8 sh = 25;
const uint8 sd = 2;
void clearLine(uint8 from,uint8 to){	
	string vidmem =(string)0xb8000;
	uint16 i = (sw * from * sd);
	for(i;i<(sw*(to+1)*sd);i++){
		vidmem[i]=0x0;
	}
	return;
}
void updateCursor(){
	unsigned temp;
	temp = cursorY * sw + cursorX;
	
	outportb(0x3D4, 14);
	outportb(0x3D5, temp >> 8);
	outportb(0x3D4, 15);
	outportb(0x3D5, temp);
	
	return;
}
void clearScreen(){
	clearLine(0,sh-1);
	cursorX = 0;
	cursorY = 0;
	updateCursor();
}
void scrollUp(uint8 lineNumber){
	string vidmem = (string)0xb8000;
	uint16 i = 0;
	for(i;i<sw*(sh-1)*sd;i++){
		vidmem[i] = vidmem[i+sw*sd*lineNumber];
	}
	clearLine(sh-1-lineNumber,sh-1);
	if((cursorY-lineNumber)<0){
		cursorX = 0;
		cursorY = 0;
	}else{
		cursorY-= lineNumber;
	}
	updateCursor();
	return;
}
void newLineCheck(){
	if(cursorY>=(sh-1)){
		scrollUp(1);
	}
	return;
}
void printch(char c){
	string vidmem = (string)0xb8000;
	switch(c){
		case 0x08://back space
			if(cursorX > 0){
				cursorX--;
				vidmem[(cursorY * sw + cursorX)*sd]=0x00;
			}
			break;
		case 0x09://tab
			cursorX = (cursorX + 8) & ~(8-1);
			break;
		case '\r':
			cursorX = 0;
			break;
		case '\n':
			cursorX = 0;
			cursorY++;
			break;
		default:
			vidmem[(cursorY*sw+cursorX)*sd]=c;
			vidmem[(cursorY*sw+cursorX)*sd+1]=0x0F;
			cursorX++;
			break;
	}
	if(cursorX >= sw){
		cursorX = 0;
		cursorY++;	
	}
	newLineCheck();
	//updateCursor();
	return;
}
void print(string ch){
	uint16 i = 0;
	uint16 len= strlength(ch);
	for(i;i<len;i++){
		printch(ch[i]);
	}
}

