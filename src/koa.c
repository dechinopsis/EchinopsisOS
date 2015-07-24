#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
void kmain(){
	clearScreen();
	print("\n");
	while(1){		
		print("Echinopsis> ");
		string ch = readStr();
		if(strEql(ch,"kuria")){
			clearScreen();
		}
		else if(strEql(ch,"")){
			//enter
		}
		else{
			print("\ncommand not found");
		}
		print("\n");
	}
	return;
}
