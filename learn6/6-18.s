	.section .data  
       mynum:  
	   .int 8  
	   mygs:  
	   .asciz "%x----%x----%x\n"  
	.section .text  
	   .globl main  
	   main:  
	      leal mynum,%eax #将mynum地址复制到%eax    
	      movl (%eax),%ebx#将%eax内地址所指内容复制到%ebx  
	      movl mynum,%ecx#将mynum内容复制到%ecx中  
	      push %ecx  
	      push %ebx  
	      push %eax  
	      push $mygs  
	      call printf  
	      push $0  
	      call exit
