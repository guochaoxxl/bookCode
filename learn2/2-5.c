#include <stdio.h>
int main(){
        int mynum;
        int ispass=0;
        while(1){
        printf("你好，请输入一个数字:");
        scanf("%d",&mynum);
        if (mynum>500 ||mynum<1){
                printf("数字仅限于1-500之间\n");
        }
        else{
                printf("\n你输入的数字是:%d\n",mynum);
                break;
        }
        } 
} 
