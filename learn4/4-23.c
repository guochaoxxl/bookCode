#include <stdio.h>
#include <stdlib.h>
int add(int a,int b){
        return a+b;
}
int sub(int a,int b){
        return a-b;
}
int main(int argc,char **argv){
        int (*operate_func[])(int,int)={
                add,sub};
        int myresult=0;
        int oper=atoi(*++argv);
        printf ("%d\n",oper);
        int mynum;
        while (*++argv!=NULL)
        {
                mynum=atoi(*argv);
                printf ("%d  ",mynum);
                myresult=operate_func[oper](myresult,mynum);
        }
        printf ("\n%d\n",myresult);
        return 0;
}
