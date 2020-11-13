#include <stdio.h>
int main(void){
        int result;
        int x=50;
        int y=30;
        myswap(&x,&y);
        printf("x:%d-y:%d\n",x,y);
	return 0;
}
int myswap(int *a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
}
