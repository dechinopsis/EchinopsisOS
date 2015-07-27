#include "util.h"
void memoryCopy(char *source,char *dest,int nbytes){
	int i;
	for(i=0;i<nbytes;i++){
		*(dest + i) = *(source + i);
	}
}
void memorySet(uint8 *dest,uint8 val,uint32 len){
	int i;
	for(i=0;i<len;i++){
		*(dest + i) = val;
	}
	//uint8*temp =(uint8 *)dest;
	//for(;len!=0;len--)*temp++=val;
}
void intToAscii(int n,char *str){
	if(n==0){
		str ="0";		
	}else{
		int i = 0;
		if(n<0){
			n = n*-1;
			str[i++] = '-';
		}		
		int mul =1;
		while(n/mul!=0){
			mul = mul*10;
		}
		mul = mul / 10;	
		int currVal = 0;
		while(mul!=0){
			currVal = n / mul;
			n = n % mul;
			mul = mul / 10;
			str[i++]=currVal+'0';
		}
		str[i] = 0;
	}
}
