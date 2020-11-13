#include <stdio.h>
int main(){
        int mynum;
        int ispass=0;
        do{
        printf("你好，请输入一个数字:");
        scanf("%d",&mynum);
        if (mynum>500 ||mynum<1){
                ispass=0;
                printf("数字仅限于1-500之间\n");
        }
        else{
                ispass=1;
                printf("\n你输入的数字是:%d\n",mynum);
        }
        } while (!ispass);
}
