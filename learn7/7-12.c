#include <stdio.h>  
#include <errno.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h> 
#include <sys/select.h> 
//服务器myhaspl
ssize_t readn(int fd,void *ptr,size_t maxcn){//读取n个字符,maxc为读取的数目  
    size_t noreadcn,readcn;  
    char *buf=ptr;  
     
    noreadcn=maxcn;  
    while(noreadcn>0){  
       if ( (readcn=read(fd,buf,noreadcn))<0){//读数据  
      
          if (errno==EINTR) {//数据读取前，操作被信号中断  
             perror("中断错误");  
             readcn=0;             
          }  
          else {return -1;}//无法修复错误，返回读取失败  
       }  
       else if(readcn==0) break;//EOF  
         
         
       noreadcn-=readcn;//读取成功，但是如果读取的字符数小于maxc，则继续读，因为可能数据还会继续通过网络送过来      
       buf+=readcn;    
       if (*buf==0) break;//如果读到字符串结尾标志则退出，必须有这句，否则会死循环  
       }    
  
         
    return (maxcn-noreadcn);  
}  
  
ssize_t  writen(int fd,void *ptr,size_t maxcn){//写入n个字符  
    size_t nowritecn,writecn;  
    char *buf=ptr;  
   
    nowritecn=maxcn;  
    while(nowritecn>0){  
       if((writecn=write(fd,buf,nowritecn))<=0){//写数据  
         
          if (errno==EINTR) {//数据写前，操作被信号中断  
             perror("中断错误");  
             writecn=0;               
          }  
          else {return -1;}//无法修复错误，返回读取失败  
       }  
  
        
       nowritecn-=writecn;  
       buf+=writecn;    
  
       }   
  
       return (maxcn-nowritecn);  
}  
  
int main(void){  
    int fd;  
    int addresslen;  
    struct sockaddr_in address;//地址信息结构  
    int pid;  
    int rc;  
    fd_set fdset;  
      
  
  
                    
    //建立socket  
    fd=socket(AF_INET,SOCK_STREAM,0);//fd为socket  
    if (fd==-1){//错误，类型从errno获得  
        perror("error");//perror先输出参数，后跟":"加空格，然后是errno值对应的错误信息(不是错误代码)，最后是一个换行符。          
    }  
      
    //bind 到socket fd      
    address.sin_family=AF_INET;//IPV4协议,AF_INET6是IPV6  
    address.sin_addr.s_addr=htonl(INADDR_ANY);//l表示32位，htonl能保证在不同CPU的相同字节序  
    address.sin_port=htons(1253);//端口号，s表示16位  
    addresslen=sizeof(address);  
      
  
    bind(fd,(struct sockaddr *)&address,addresslen);//bind  
      
           //建立socket队列，指定最大可接受连接数  
           rc=listen(fd,32);//最多接收32个连接，开始监听  
           //int listen(int sockfd, int backlog)返回：0──成功， -1──失败  
           //内核会在自己的进程空间里维护一个队列以跟踪这些完成的连接但服务器进程还没有接手处理或正在进行的连接  
           if (rc==-1) {  
              perror("listen error");//监听失败  
              exit(1);  
           }  
           printf("server wait....\n");             
           while(1){  
  
              struct sockaddr_in clientaddress;  
              int address_len;  
              int client_sockfd;  
              char mybuf[100];      
              char *buf="hello\n";    
              struct timeval timeout;//超时结构体  
              //超时为2秒  
              timeout.tv_sec=1;  
              timeout.tv_usec=0;  
              //设置fdset  
              FD_ZERO(&fdset);//清除fdset  
              FD_CLR(fd,&fdset);//清除fd的标志  
              FD_SET(fd,&fdset);//设置标志  
              //select  
              if ((select(fd+1,&fdset,NULL,NULL,&timeout))<0){  
                  perror("select error");  
                  fflush(stdout);                
              }  
              //等待连接，使用新的进程或线程来处理连接  
              fflush(stdout);       
              address_len=sizeof(clientaddress);                
              if(FD_ISSET(fd,&fdset)){  
                  //如果有连接到来  
                 client_sockfd=accept(fd,(struct sockaddr *)&clientaddress,&address_len);//client_sockfd可理解为一个文件句柄，能用read和write操作。client_address是客户端信息结构 myhaspl  
                
              //fork进程来处理每个客户的连接        
                  pid=fork();  
               if (pid<0){//错误  
                    printf("error:%s\n",strerror(errno));//strerror将errno映射为一个错误信息串 myhaspl  
                    close(client_sockfd);  
                    exit(1);   
                }     
  
                 if (pid==0){ //子进程处理每个客户端的数据              
                     close(fd);//子进程关闭不需要它处理的监听资源  
  
                      //读取数据 myhaspl  
                      bzero(mybuf,100);                     
                      readn(client_sockfd,(void *)mybuf,100);  
                      printf("\nserver read :%s",mybuf);                    
                     //发送数据                    
                      writen(client_sockfd,(void *)buf,strlen(buf)+1);                 
                       printf("\nserver send :%s",buf);                  
                       close(client_sockfd);  
                       exit(0);  
                 }  
                  else {//父进程  
                          close(client_sockfd);//父进程不处理客户端连接，因此关闭，但并不意味着把子进程的处理句柄关闭，因为子进程继承了父进程的client_sockfd资源       
                 }                                 
            }else{  
                  printf(".");  
                  fflush(stdout);  
            }  
       }  
 } 
