#include <stdio.h>
int main(void){
        int i;
        int x[2][5]={1,2,3,4,5,6,7,8,9,10};
        int (*p_x)[5];
        for (p_x=x;p_x<=(&x[1]);p_x++){
                printf("%d   ",*p_x[0]); 
        }
        return 0;
}    
