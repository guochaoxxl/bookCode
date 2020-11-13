#include <pthread.h>  
#include <stdio.h>  
#include <errno.h>  
void *mycompadd(void *xx){//参数必须为void *，然后进行强制类型转换  
  int sum=0;   
  int *x=(int *)(xx);  
  int contscope;  
  pthread_attr_t attr;        
  pthread_getattr_np(pthread_self(),&attr);//获取线程属性。   
  pthread_attr_getscope(&attr,&contscope); //获取线程属性对象竞争域  
  if (contscope==PTHREAD_SCOPE_SYSTEM){//系统调度竞争域  
     printf("mycompadd系统竞争\n");  
  }  
  if(contscope==PTHREAD_SCOPE_PROCESS){//进程调度竞争域  
     printf("mycompadd进程竞争\n");         
  }    
  for (int i=0;i<*x;i++){  
    sum+=i;   
  }  
  printf("add%d\n",sum);      
}  
void  *mycompchen(void *xx){//参数必须为void *，然后进行强制类型转换  
  int sum=1;   
  int *x=(int *)(xx);  
  int contscope;  
  pthread_attr_t attr;    
    
  pthread_getattr_np(pthread_self(),&attr);//获取线程属性。   
  pthread_attr_getscope(&attr,&contscope); //获取线程属性对象竞争域  
  if (contscope==PTHREAD_SCOPE_SYSTEM){//系统调度竞争域  
     printf("mycompchen系统竞争\n");  
  }  
  if(contscope==PTHREAD_SCOPE_PROCESS){//进程调度竞争域  
     printf("mycompchen进程竞争\n");         
  }  
  for (int i=1;i<=*x;i++){  
    sum*=i;    
  }  
  printf("chen%d\n",sum);     
}  
   
   
int main(){  
  //main为boss线程  
  int n=5;  
  pthread_t threada,threadb;   
  pthread_attr_t attr;  
  pthread_attr_init(&attr);  
  //创建worker线程，并执行线程  
  pthread_attr_setscope(&attr,PTHREAD_SCOPE_SYSTEM); //设置线程属性对象竞争域为 系统调度竞争，在整个系统内进行竞争。  PTHREAD_SCOPE_PROCESS在LINUX系统下不支持，因此设置为PTHREAD_SCOPE_PROCESS会出错,不成功  
  //通常pthread的这些函数返回0值，表示成功  
  //返回EINVAL,表示不正确的可选项  
  //ENOTSUP，系统不支持或权限不够  
   if (pthread_attr_setscope(&attr,PTHREAD_SCOPE_PROCESS)==ENOTSUP){//如果在LINUX下运行这段程序，肯定不支持，SOLARIS支持
      printf("LINUX系统不支持系统调度竞争\n");  
   }     
  
  pthread_create(&threada,NULL,mycompadd,&n);//线程，线程属性，函数，参数。如果有多个参数，必须传结构指针  
  pthread_create(&threadb,&attr,mycompchen,&n);//线程，线程属性，函数，参数  
  
  sleep(1);  
  return(0);  
}  
