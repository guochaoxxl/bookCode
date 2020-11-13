#include <stdio.h>
int main(void){
        int i;
        char x[20]="0123456789ABCDEFGHIJ";
        for (i=0;i<20;i++){
        printf("x[%d]:%c\n",i,x[i]);
        }
        char *p_x;
        for (p_x=&x[0];p_x<&x[20];p_x++){
                printf("%c",*p_x);
        }
        printf ("\n");
        return 0;
}
