#include <stdio.h>
int main(int argc,char ** argv){
    int a[]={12,33,44,55,66,77,88,99};
    int *const cpr;
    for(cpr=a; cpr<=&a[7]; cpr++){
        printf("%d\n",*cpr);
    }
    return 0;
}
