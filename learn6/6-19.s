	.section .data  
	.section .text  	  
	  .globl main  
	  main:  
	    movl $2,%eax  
	  
	    movl $5,%ebx  
	  
	    mul  %ebx   #%eax*%ebx->%eax，无符号乘法  
	  
	    movl $-2,%eax  
	  
	    movl  $5,%ebx  
	  
	    imul  %ebx#%eax*%ebx->%eax，有符号乘法   
