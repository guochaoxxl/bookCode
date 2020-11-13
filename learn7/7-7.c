#include <pthread.h>
#include <stdio.h>
#define MAXS 1000 
  pthread_mutex_t mutex; 
  double myjg[MAXS+1];//计算结果存放位置
  int max;
void *mycomp(void *x){//计算1/i的结果，计算结果放在一个数组中。
int i;
pthread_mutex_lock(&mutex); //互斥临界区，完成对i的累加，保证不被多个线程同时修改i
myjg[0]++;
i=myjg[0];//myjg[0]存放着线程已经计算到的i。
pthread_mutex_unlock(&mutex); 
myjg[i]=(1/(double)i);
printf("1/%d finished,result %.10f\n",i,myjg[i]); 
}
void *myprint(void *xx){//将计算结果累加，最终完成1+1/2+1/3+......+1/n的计算
int maxi;
double jg;
  while(1)
  {
	  sleep(1);
	  pthread_mutex_lock(&mutex); //互斥临界区，取出正确的i，保证此时没有线程写i
	  maxi=myjg[0];
      pthread_mutex_unlock(&mutex);
      if (maxi>=max){//1/i已经计算完毕
            for (int i=1;i<=max;i++){
  		        jg+=myjg[i];
                printf("%.10f added\n",myjg[i]);   		        
  		    }
  		 printf("result:%.10f\n",jg);//输出累加结果。
  		 break;
	     }
  }
}
int main(){
//计算1+1/2+1/3+......+1/n
  pthread_t threads[MAXS+1];
  printf("please input an integer:(<=%d)",MAXS);
  while (scanf("%d",&max),max>MAXS){//n的最大值
      printf("please input an integer:(<=%d)",MAXS);
  };
  myjg[0]=0;
  pthread_create(&(threads[0]),NULL,myprint,NULL);      
  for (int i=1;i<=max;i++){
    pthread_create(&(threads[i]),NULL,mycomp,NULL);  
  } 
  sleep(1); 
  for (int i=0;i<=max;i++){
    pthread_join(threads[i],NULL);  	
  }  
  pthread_mutex_destroy(&mutex);
  return(0);
}
