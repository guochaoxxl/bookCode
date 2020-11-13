#include <stdio.h>  
	int main(void){  
	    int xa=2;  
	    int xb=6;  
	     asm volatile(  
	    "subl %1,%0\n\t"   
	     :"=r"(xb):"r"(xa),"0"(xb));      
	    printf("%d\n",xb);  
	    return 0;  
} 
