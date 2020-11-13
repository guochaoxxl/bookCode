#include <stdio.h>
int main(int argc,char ** argv){
    int a[]={12,33,44,55,66,77,88,99};
    const int *const cpr;
    for(cpr=a; cpr<=&a[7]; cpr++){
        (*cpr)++;
        printf("%d\n",*cpr);
    }
    return 0;
}
