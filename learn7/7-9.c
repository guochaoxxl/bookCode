#include <pthread.h>
#include <stdio.h>
struct mydata{
       int x;
       char c[4];
};
pthread_t pthreada,pthreadb;
pthread_key_t datakey;//每个进程创建一次,不同的线程，同样名字的键指向不同的地方
void *cleanup_mydata(void *dataptr){//删除键时调用的
    free((struct mydata*)dataptr);
}
void anum1(){
    int rc;
    struct  mydata *mdata=(struct mydata*)malloc(sizeof(struct mydata));
    mdata->x=1;
    mdata->c[0]='a';
    mdata->c[1]='\0'; 
    rc=pthread_setspecific(datakey,(void*)mdata);//设置键指向的值,注意这个mdata为值的内存，必须使用指针的方式指向内存 
    sleep(1);
    struct  mydata *mmdata=(struct mydata*)pthread_getspecific(datakey);//取出键指向的值,注意这个mdata为值的内存，必须使用指针的方式指向内存 
    printf("-%d-%s\n",mmdata->x,mmdata->c); 
    fflush(stdout); 
}
void bnum2(){
    int rc;
    struct  mydata *mdata=(struct mydata*)malloc(sizeof(struct mydata));
    mdata->x=2;
    mdata->c[0]='b';
    mdata->c[1]='\0'; 
    rc=pthread_setspecific(datakey,(void*)mdata);//设置键指向的值,注意这个mdata为值的内存，必须使用指针的方式指向内存 
    sleep(1);
    struct  mydata *mmdata=(struct mydata*)pthread_getspecific(datakey);//取出键指向的值,注意这个mdata为值的内存，必须使用指针的方式指向内存 
    printf("-%d-%s\n",mmdata->x,mmdata->c);
    fflush(stdout); 
}
int main(void){
    int rc;
    rc=pthread_key_create(&datakey,cleanup_mydata);//为键删除时的清理函数
    pthread_create(&pthreada,NULL,anum1,NULL); 
    pthread_create(&pthreadb,NULL,bnum2,NULL);  
    sleep(3);
    pthread_join(pthreada,NULL);   
    pthread_join(pthreadb,NULL);  
    rc=pthread_key_delete(datakey); //仅删除键，但不删除值指向的内存，线程终止调用用户自定义的删除函数,本例中为cleanup_mydata
}
