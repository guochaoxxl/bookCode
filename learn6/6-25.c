#include <stdio.h>  
	int main(void){  
	    int xa=6;  
	    int xb=2;  
	    int result;  
	   //使用占位符，由r表示，编译器自主选择使用哪些寄存器
	    asm volatile(  
	    "add %1,%2\n\t"   
	    "movl %2,%0"  
	     :"=r"(result):"r"(xa),"r"(xb));      
	    printf("%d\n",result);  
	    return 0;  
	}  
