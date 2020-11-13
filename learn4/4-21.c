#include <stdio.h>
int add(int a,int b);
int main(void){
        int (*myfunc)(int a,int b);
        myfunc=add;
        int x=myfunc(12,36);
        printf("%d",x);
        return 0;
}
int add(int a,int b){
        return a+b;
}
