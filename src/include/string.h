#ifndef STRING_H
#define STRING_H

#include "types.h"
uint16 strlength(string ch){
	uint16 ln = 0;
	while(ch[ln]){
		ln++;
	}
	return ln;
}
uint8 strEql(string str1,string str2){
	uint8 result = 0;
	uint16 strSize = strlength(str1);
	if(strSize==strlength(str2)){
		uint8 i=0;
		result = 1;
		for(i;i<strSize;i++){
			if(str1[i]!=str2[i]){
				result = 0;
				break;
			}
		}
	}
	return result;
}
#endif
