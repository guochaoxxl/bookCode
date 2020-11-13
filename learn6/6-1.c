#include <stdio.h>
long fib_n(long,long,int);
int main(){
	fib_n(0, 1, 40);
	return 0;
}
int i=0;
long fib_n(long curr,long next,int n) {
	printf("第%d项：%ld\n",i++,curr);
        if (n == 0) {
            return curr;
        } else {
            return fib_n(next, curr+next, n-1);
        }
}
