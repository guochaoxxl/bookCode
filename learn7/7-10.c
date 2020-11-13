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
	      
	    //建立消息队列  
	    queue_id=msgget(QUE_ID,IPC_CREAT|0600);//QUE_ID为一个正整数，公共消息队的ID  
	    if (queue_id==-1){  
	       perror("create queue error!\n");  
	       exit(1);  
	    }  
	    printf("message %d queue created!\n",queue_id);  
	    //创建发送消息结构  
	    printf("message send....\n");  
	    msg=(struct msgbuf*)malloc(sizeof(struct msgbuf)+100);//100为消息的长度，msgbuf构只有2个成员一个成员是mytpe，另一个成员是一个字节的mtext,在结构后分配更多的间以存放消息字符串  
	    msg->mtype=1;//消息类型，正整数  
	    strcpy(msg->mtext,"hello,world");  
	    //发送消息  
	    rc=msgsnd(queue_id,msg,100,0);  
	    //最后一个参数可以是是0与随后这些值(或者就是0):IPC_NOWAIT,如果消息类型有则立即返回，函数调用失败  
	    //MSG_EXCEPT，当消息类型大于0时，读与消息类型不同的第一条消息  
	    //MSG_NOERROR，如果消息长度大于100字节则被截掉  
	    if (rc==-1){  
	       perror("msgsnd error\n");  
	       exit(1);  
	    }  
	    free(msg);//发送完毕，释放内存  
	    printf("message sended!\n");  
	    return 0;  
	}
