#include <stdio.h>
int main(void){
        int i;
        char x[10]="ABCDEFGHIJ";
        char *p_x[10];
        for (i=0;i<10;i++){
               p_x[i]=&x[i];
        }
        for (i=0;i<10;i++){
                printf("%c ",*p_x[i]);
        }
        return 0;
}
