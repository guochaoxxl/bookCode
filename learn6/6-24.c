#include <stdio.h>  
	int main(void){  
	   //格式为：asm("汇编代码":输出位置:输入位置:改动的寄存器列表)  
	   //a为eax,ax,al;b为ebx等;c为ecx等;d为edx等;S为esi或si;D为edi或di  
	   //+读和写;=写;%如果必要，操作数可以和下一个操作数切换;&在内联函数完成之前，可以删除或重新使用操作数  
	    int xa=6;  
	    int xb=2;  
	    int result;  
	    //ansi c标准的asm有其它用，所以用__asm__,__volatile__表示内联汇编部分不用优化(可以用volatile，但是ansi c不行)，以防优化破坏内联代码组织结构  
	    asm volatile(  
	    "add %%ebx,%%eax\n\t"  
	    "movl $2,%%ecx\n\t"  
	    "mul %%ecx\n\t"      
	    "movl %%eax,%%edx"  
	     :"=d"(result):"a"(xa),"b"(xb):"%ecx");//注意扩展方式使用2个%表示      
	    printf("%d\n",result);  
	    return 0;  
	}  
