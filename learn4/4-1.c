#include <stdio.h>
int main(void){
        int x;
        x=128;
        int *myp=&x;
        int **mypp=&myp;
        printf("x:%d\n",x);
        printf("myp:%p\n",myp);
        printf("mypp:%p\n",mypp);
        printf("mypp address:%p\n",&mypp);
        return 0;
}
