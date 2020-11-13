#include <stdio.h>
#include <stdlib.h>
//code:myhaspl@myhaspl.com
//author:myhaspl
//date:2014-01-10
typedef struct listnode mynode;
struct listnode{
	mynode *next;
	char *data;
	int number;
	int age;
	};
mynode *addnode(mynode *prevnd,int number,int age,char *data){
	mynode *ndtemp=(mynode*)malloc(sizeof(mynode));
	prevnd->next=ndtemp;
	ndtemp->number=number;
	ndtemp->age=age;
	ndtemp->data=data;
	ndtemp->next=NULL;
	return ndtemp;
}
mynode *initlist(){
	mynode *temp=(mynode*)malloc(sizeof(mynode));
	temp->number=0;
	temp->age=0;
	temp->data=NULL;
	temp->next=NULL;
	return temp;
}
int  main(){
        //���ָ��ָ��ͬһ���ڴ棬����ڴ���Ϊĳ��ָ�벻��ʹ�õ�ԭ��ɾ�������ɲ������������1������(��3��Ԫ��)��Ԫ�ص�data��ָ��ͬһ���ڴ��
	mynode *mylist=initlist();
	mynode *mytempnd=mylist;
	char *mydata=(char *)malloc(100);
	const char *strsrc="helloworld";	
	strcpy(mydata,strsrc);
	int i=0;
	for(i=0;i<3;i++){
	       	mytempnd=addnode(mytempnd,i,20+i,mydata);
	}
	for (mytempnd=mylist->next;mytempnd!=NULL;mytempnd=mytempnd->next){
		printf("id:%d,age:%d,data:%s\n",mytempnd->number,mytempnd->age,mytempnd->data);
       	}
	//���潫���¹�����ڴ��ͷţ�������2���ڵ�ָ������ڴ棬�⽫�����ڴ�й¶
//���ǹ���ɾ�����һ���ڵ㣬���ͷ����һ���ڵ��dataָ��ָ����ڴ�
	printf ("-------------------------\n");
	mynode *oldtmpnd;
	for (mytempnd=mylist->next;mytempnd!=NULL;){
		oldtmpnd=mytempnd;
		mytempnd=mytempnd->next;
		if (mytempnd==NULL){
			printf("delete id:%d\n",oldtmpnd->number);
			free(oldtmpnd->data);
			free(oldtmpnd);
		}
	}
       	return 0;
}

