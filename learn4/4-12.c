#include <stdio.h>
int x[5]={1,2,3,4,5};
int main(void){
        int result;
        result=mysum(5,x);
        printf("%d\n",result);
	return 0;
}
int mysum(int length,int *data){
        int myresult=0;
        int i;
        for(i=0;i<length;i++){
                myresult+=*(data+i);
        }
        return myresult;
}
