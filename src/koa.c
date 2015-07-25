#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
void kmain(){
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
