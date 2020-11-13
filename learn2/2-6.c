#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand((int)time(0));
    printf("第一个随机数:%d 第二个随机数:%d\n",rand()%499+1,rand()%499+1);
}
