.section .data  
	  myvalue:  
	     .byte 67,68,69,70,0  
	  mygs:  
	     .asciz "%s\n"  
.section .text  
	.globl main  
	   main:  
	    movl $myvalue,%ecx  
	    push %ecx  
	    push $mygs      
        call printf  
	    push $0  
	    call exit 
