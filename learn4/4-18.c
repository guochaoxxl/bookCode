#include <stdio.h>
void plusplus(int  *const cpr){
	(*cpr)++;
}
int main(int argc,char ** argv){
    int a[]={12,33,44,55,66,77,88,99};
    int *pr;
    for(pr=a; pr<=&a[7]; pr++){
        plusplus(pr);
        printf("%d\n",*pr);
    }
    return 0;
}
