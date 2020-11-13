#include <pthread.h>  
#include <stdio.h>  
void *mycompadd(void *xx){//参数必须为void *，然后进行强制类型转换  
  int sum=0;   
  int *x=(int *)(xx);  
  int y;  
  for (int i=1;i<=*x;i++){  
    sum+=i;  
  }  
  printf("add:%d\n",sum);  
}  
void  *mycompchen(void *xx){//参数必须为void *，然后进行强制类型转换  
  int sum=1;   
  int *x=(int *)(xx);  
  for (int i=1;i<=*x;i++){  
    sum*=i;    
  }  
  printf("chen:%d\n",sum);     
}  
int main(){  
  //线程分离后，不能再合并  
  //main为boss线程，  
  pthread_t threada,threadb,threadc;  
  pthread_attr_t detachedatrr;  
  //创建worker线程，并执行线程  
  int n=5;  
  pthread_create(&threada,NULL,mycompadd,&n);//线程，线程属性，函数，参数。线程默认可合并  
  pthread_create(&threadb,NULL,mycompchen,&n);//线程，线程属性，函数，参数。线程默认可合并  
    
  pthread_attr_init(&detachedatrr);  //初始化线程属性对象  
  pthread_attr_setdetachstate(&detachedatrr,PTHREAD_CREATE_DETACHED);//直接设置线程的可分离属性，不可合并，PTHREAD_CREATE_JOINABLE为可合并，PTHREAD_CREATE_DETACHED为可分离,设置可分离后，不能再合并  
  pthread_create(&threadc,&detachedatrr,mycompchen,&n);//线程，线程属性，函数，参数,这个线程是不可合并，可分离的，通过线程属性直接设定的。  
    
  pthread_detach(threadb);//动态分离线程threadb  
  //wait worker线程，并合并到BOSS线程来  
  pthread_join(threada,NULL);  
  return(0);  
}  
