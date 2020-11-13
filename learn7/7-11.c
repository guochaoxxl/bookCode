#define _GNU_SOURCE  
	#include <stdio.h>  
	#include <sys/ipc.h>  
	#include <sys/msg.h>  
	#include <sys/types.h>  
	#define QUE_ID 2  
	  
	//使用公共消息队列，读写进程可以不同时运行。  
	int main(void){  
	    int queue_id;  
	    struct msgbuf *msg;  
	    int rc;  
	      
	    //取得消息队列  
	    queue_id=msgget(QUE_ID,0);//QUE_ID为一个正整数，公共消息队列的ID,  
	  
	  
	    if (queue_id==-1){  
	       perror("get queue error!\n");  
	       exit(1);  
	    }  
	  
	    printf("message recv....\n");  
	    msg=(struct msgbuf*)malloc(sizeof(struct msgbuf)+100);  
	    rc=msgrcv(queue_id,msg,101,0,0);  
	    if (rc==-1){  
	       perror("recv error\n");  
	       exit(1);  
	    }  
	    printf("recv:%s\n",msg->mtext);     
	     
	    return 0;  
	}  
