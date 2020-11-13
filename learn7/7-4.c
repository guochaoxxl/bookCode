#include <pthread.h>  
#include <stdio.h>  
#define MAXTHREADS 3   
void *mycompprint(void *xx){//参数必须为void *，然后进行强制类型转换  
  int oldstate,oldtype;    
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,&oldstate);//设置线程是可以中止的。  
  pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,&oldtype);//设置线程推迟中止，PTHREAD_CANCEL_DEFERRED为默认值。  
  int *x=(int *)(xx);    
  for (int i=1;i<*x;i++){  
    if ((i%250)==0) {//如果i为250的倍数则取消  
     printf("%dprint:%d\n",*x,i);       
     pthread_testcancel();//pthread_testcancel()检测是否需要取消，设置取消点，如果有挂起的取消请求，则在此处中止本线程  
    }      
  }  
}  
void *mycompadd(void *xx){//参数必须为void *，然后进行强制类型转换  
  int oldstate,oldtype;    
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,&oldstate);//设置线程是可以中止的。  
  pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS,&oldtype);//设置线程线程立即中止,PTHREAD_CANCEL_ASYNCHRONOUS表示线程立即终止。  
  int sum=0;   
  int *x=(int *)(xx);  
  int y;  
  for (int i=1;i<=*x;i++){  
    sum+=i;   
    printf("%dadd%d\n",i,sum);      
  }  
}  
void  *mycompchen(void *xx){//参数必须为void *，然后进行强制类型转换  
  int oldstate,oldtype;    
  pthread_setcancelstate(PTHREAD_CANCEL_DISABLE,&oldstate);//设置线程不能中止的。    
  int sum=1;   
  int *x=(int *)(xx);  
  for (int i=1;i<=*x;i++){  
    sum*=i;      
    printf("%dchen%d\n",i,sum);        
  }  
}  
 
int main(){  
  //线程分离后，不能再合并  
  //main为boss线程，  
  pthread_t threads[MAXTHREADS];//创建线程池  
  void *status;  
  //创建worker线程，并执行线程  
  int n1=25;  
  int n2=10000;  
  
  pthread_create(&(threads[0]),NULL,mycompprint,&n2);     
  pthread_create(&(threads[1]),NULL,mycompadd,&n1);   
  pthread_create(&(threads[2]),NULL,mycompchen,&n1);   
    
  for (int i=0;i<MAXTHREADS;i++){  
       pthread_cancel(threads[i]);    
  }    
  for (int i=0;i<MAXTHREADS;i++){  
       pthread_join(threads[i],&status);  //wait worker线程，并合并到BOSS线程来  
       if (status==PTHREAD_CANCELED){  
        printf("thread%d 已经取消!\n",i);  
       }  
       else{  
        printf("thread%d 不能被取消!\n",i);  
       }         
  }   
  return(0);  
} 
