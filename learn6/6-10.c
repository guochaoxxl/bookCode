#include <stdio.h>
int add(char a,char b,char *result){
    *result=a+b;
    return *result;
}
int main(void){
   char a=90;
   char b=120;
   char c=20;
   char res=0;
   char myres;
   myres=add(a,b,&myres);
   printf("%d\n",myres);
   myres=add(a,-b,&myres);
   printf("%d\n",myres);
   myres=add(a,c,&myres);
   printf("%d\n",myres);
}
