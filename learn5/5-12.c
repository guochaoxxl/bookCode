#include <stdio.h>
#include <stdlib.h>
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
	//�������������������
	//���������Ԫ��
	for (mytempnd=mylist->next;mytempnd!=NULL;mytempnd=mytempnd->next){
		printf("id:%d,age:%d\n",mytempnd->number,mytempnd->age);
	}
	//Ȼ��ɾ�������е�����Ԫ��
	mynode* oldtmpnd;
	for (mytempnd=mylist->next;mytempnd!=NULL;){
		printf("delete id:%d\n",mytempnd->number);
		oldtmpnd=mytempnd;
		mytempnd=mytempnd->next;
		free(oldtmpnd);
	}
	free(mylist);
//�������γ��ڴ�й¶�ڶ������-����ָ�����ʾ
	//���ɲ�������������ǰ����ͬ
	mylist=initlist();
	mytempnd=mylist;
	i=0;
	for(i=0;i<10;i++){
		mytempnd=addnode(mytempnd,i,20+i);
	}
	for (mytempnd=mylist->next;mytempnd!=NULL;mytempnd=mytempnd->next){
		printf("id:%d,age:%d\n",mytempnd->number,mytempnd->age);
	}
//���ǹ���ɾ����������4���ڵ㣬�����õ�6��Ԫ�ص�nextָ��ĵ�ַ��Ч��
	//��ָ���Ѿ�ɾ���ĵ�7���ڵ㣬��������ָ��
	printf ("-------------------------\n");
	int j=0;
	for (mytempnd=mylist->next;mytempnd!=NULL;){
		oldtmpnd=mytempnd;
		mytempnd=mytempnd->next;
		if (++j>6){
		printf("delete id:%d\n",oldtmpnd->number);
		free(oldtmpnd);
		}
	}
       	return 0;
}

