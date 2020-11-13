#include <stdio.h> 
int c=6;  
int d=2;  
int result;   
int main(void){  
    asm("pusha\n\t"  
    "movl c,%eax\n\t"  
    "movl d,%ebx\n\t"  
    "add %ebx,%eax\n\t"  
    "movl %eax, result\n\t"  
    "popa");//使用全局C变量c和d      
    printf("%d\n",result);      
    return 0;  
}  
