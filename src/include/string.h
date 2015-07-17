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
#endif
