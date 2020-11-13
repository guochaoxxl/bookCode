#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//code:myhaspl@myhaspl.com
//date:2014-01-23
int getnumber(){
        srand((int)time(0));
        return rand()%499+1;
}
int main(){
        int mynum;
        int ispass=0;
        int guessnum=getnumber();
        int myrange[2]={1,500};
        while (1){
        mynum=(myrange[0]+myrange[1])/2;
        if (mynum>guessnum){
                printf("程序猜的数字为%d，数字大了！\n",mynum);
                myrange[1]=mynum;
        }
        else if(mynum<guessnum){
                printf("程序猜的数字为%d，数字小了！\n",mynum);
                myrange[0]=mynum;
        }
        else{
                printf("程序猜的数字为%d， 被猜的数字为%d,猜中了！\n",mynum,guessnum);
                break;
        } 
        }
} 
