#include <stdio.h>
int main(int argc,char ** argv){
    int a[]={12,33,44,55,66,77,88,99};
    int *pr;
    for(pr=a;pr<=&a[7];pr++){
       (*pr)++;    
    }
    const int* cpr;
    for(cpr=a;cpr<=&a[7];cpr++){
        printf("%d\n",*cpr); 
    } 
    return 0;
}
