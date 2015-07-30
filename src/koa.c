#include "include/kb.h"
#include "include/isr.h"
#include "include/idt.h"
void kmain(){
	isr_install();	
	clearScreen();
	while(1){		
		print("Echinopsis> ");
		string ch = readStr();
		if(strEql(ch,"kuria")){
			clearScreen();
			continue;
		}
		else if(strEql(ch,"")){
			//enter
		}
		else{
			print("\n");
			print(ch);
			print(": command not found");
		}
		print("\n");
	}
	return;
}
