#include <pthread.h>
#include <stdio.h>
 //2个工作线程，分别是累加和累乘
void *mycompadd(void *xx){//参数必须为void *，然后进行强制类型转换
  int sum=0; 
  int *x=(int *)(xx);
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
  //main为boss线程，
  pthread_t threada,threadb;
  //创建worker线程，并执行线程
  int n=3;
  pthread_create(&threada,NULL,mycompadd,&n);//线程，线程属性，函数，参数。如果有多个参数，必须传结构指针
  pthread_create(&threadb,NULL,mycompchen,&n);//线程，线程属性，函数，参数
  //wait worker线程，并合并到BOSS线程来
  pthread_join(threada,NULL);
  pthread_join(threadb,NULL);
  return(0);
}
