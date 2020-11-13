#include <stdio.h>
int main(void){
        int i;
        char x[10]="ABCDEFGHIJ";
        char *p_x[10];
        for (i=0;i<10;i++){
               p_x[i]=x+i;
       }
        char **pp_x=NULL;
        for (i=0;i<10;i++){
                printf("%c ",*p_x[i]);
        }
        printf ("\n");
        for (pp_x=p_x;pp_x<(p_x+10);pp_x++){
                printf("%c   ",**pp_x);
        }
        return 0;
}
