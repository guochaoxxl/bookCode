#include <stdio.h>
struct mynum{
int a;
int b;
int result;
void (*mod_add)(int a,int b,int *result);
};
void madd(int a,int b,int *result){
        (*result)=(a+b)%13;
}
int main(void){
        struct mynum mnum;
	mnum.a=12;
        mnum.b=26;
        mnum.mod_add=madd;
        mnum.mod_add(mnum.a,mnum.b,&mnum.result);
        printf("%d\n",mnum.result);
        return 0;
}
