#include <stdio.h>  
	int c=10;  
	int d=20;  
	int addresult;  
	int main(void){  
	    int a=6;  
	    int b=2;  
	    int result;  
	    result=a*b;  
	    //ansi c标准的asm有其它用，所以用__asm__,__volatile__表示内联汇编部分不用优化(可以用volatile，但是ansi c不行)，以防优化破坏内联代码组织结构  
        printf("%d\n",result);  
	    __asm__ __volatile__("pusha\n\t"  
	    "movl c,%eax\n\t"  
	    "movl d,%ebx\n\t"  
	    "add %ebx,%eax\n\t"  
	    "movl %eax, addresult\n\t"  
	    "popa");//使用全局C变量c和d      
	    printf("%d\n",addresult);      
	    return 0;  
}  
