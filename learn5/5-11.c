#include <stdlib.h>
#include <stdio.h>
//code:myhaspl@myhaspl.com
//author:myhaspl
//date:2014-01-10
typedef struct listnode mynode; 
struct listnode{
	mynode *next;
	int number;
	int age;
	};
mynode *addnode(mynode *prevnd,int number,int age){
	mynode *ndtemp=(mynode*)malloc(sizeof(mynode));
	prevnd->next=ndtemp;
	ndtemp->number=number;
	ndtemp->age=age;
	ndtemp->next=NULL;
	return ndtemp;
}
mynode *initlist(){
	mynode *temp=(mynode*)malloc(sizeof(mynode));	
	temp->number=0;
	temp->age=0;
	temp->next=NULL;
	return temp;
}
int  main(){
	mynode *mylist=initlist();
	mynode *mytempnd=mylist;
	int i=0;
	for(i=0;i<10;i++){
		mytempnd=addnode(mytempnd,i,20+i);
	}
	//下面是正常的链表操作
	//先输出链表元素
	for (mytempnd=mylist->next;mytempnd!=NULL;mytempnd=mytempnd->next){
		printf("id:%d,age:%d\n",mytempnd->number,mytempnd->age);
	}
	//然后删除链表中的所有元素
	for (mytempnd=mylist->next;mytempnd!=NULL;mytempnd=mytempnd->next){
		printf("delete id:%d\n",mytempnd->number);
		free(mytempnd);
	}
	free(mylist);
	//下面是形成内存泄露第一种情况-垃圾的演示
	//生成并输出链表，这个与前面相同
	mylist=initlist();
	mytempnd=mylist;
	i=0;
	for(i=0;i<10;i++){
		mytempnd=addnode(mytempnd,i,20+i);
	}
	for (mytempnd=mylist->next;mytempnd!=NULL;mytempnd=mytempnd->next){
		printf("id:%d,age:%d\n",mytempnd->number,mytempnd->age);
	}
	//删除链表，我们故意留下后面6个链表节点无法删除，导致后面6个链表节点形成垃圾
	int j=0;
	for (mytempnd=mylist->next;mytempnd!=NULL;mytempnd=mytempnd->next){
		if (++j>3){
			mytempnd->next=NULL;
			break;
		}
	}

	for (mytempnd=mylist->next;mytempnd!=NULL;mytempnd=mytempnd->next){
		printf("delete id:%d\n",mytempnd->number);
		free(mytempnd);
		j++; 
	}
       	return 0;	
}

