#include <stdio.h>  
	int main(void){  
	    int xa=6;  
	    int xb=2;  
	    asm volatile(  
	    "add %[mya],%[myb]\n\t"   
	     :[myb]"=r"(xb):[mya]"r"(xa),"0"(xb));      
	    printf("%d\n",xb);  
	    return 0;  
	}  
