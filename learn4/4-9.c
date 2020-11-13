#include <stdio.h>
int main(void){
        int i;
        int x[2][5]={1,2,3,4,5,6,7,8,9,10};
        int *p_x=&x[0][0];
        for (;p_x<&x[1][5];p_x+=2){
                printf("%d   ",*p_x);
        }
        return 0;
}
