#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getnumber(){
    	srand((int)time(0));
        return rand()%499+1;
}
int main(){
	int mynum;
	int ispass=0;
	int guessnum=getnumber();
	while (1){
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
	if (mynum>guessnum){
		printf("数字大了！\n");
	}
        else if(mynum<guessnum){
		printf("数字小了！\n");
	}
	else{
		printf("祝贺您，您猜中了！\n");
		break;
	}		
	}
}
