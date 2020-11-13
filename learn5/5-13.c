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
        //多个指针指向同一个内存，这个内存因为某个指针不再使用的原因删除，生成并输出链表，生成1个链表(共3个元素)，元素的data都指向同一个内存块
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
	//下面将导致共享的内存释放，但仍有2个节点指向这个内存，这将导致内存泄露
//我们故意删除最后一个节点，并释放最后一个节点的data指针指向的内存
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

