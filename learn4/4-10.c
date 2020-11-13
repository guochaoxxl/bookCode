#include <stdio.h>
int main(void){
        int x[2][5]={{1,2,3,4,5},{6,7,8,9,10}};
        int i,j;
        for (i=0;i<2;i++){
                for (j=0;j<5;j++){
                        printf("%d   ",*(*(x+i)+j));
                }
        }
        return 0;
}
