int main(void){
int a=88;
int b=2;
int result=a*b;  
asm("nop\n\t"  
"nop\n\t"  
"nop\n\t"  
"nop");
//4个nop指令，\n\t表示换行，然后加上TAB行首空，因为每个汇编指令必须在单独一行，需要换行，加上制表符是为了适应某些编译器的要求。      
printf("%d\n",result);  
return 0;
}
