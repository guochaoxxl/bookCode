#include <stdio.h>
int main(void){
        int i;
        char x[10]="ABCDEFGHIJ";
        char **pp_x[5];
        char *p_x[10];
        for (i=0;i<10;i++){
               p_x[i]=x+i;
       }
        char ***temp_x=pp_x;
        for (i=0;i<10;i+=2){
                *temp_x=&p_x[i];
                temp_x++;
        }
        printf ("\n");
        char ***ppp_x;
        for (ppp_x=pp_x;ppp_x<(pp_x+5);ppp_x++){
                printf("%c   ",***ppp_x);
        }
        return 0;
}
