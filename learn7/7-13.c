#include <stdio.h>  
#include <errno.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <netinet/in.h>  
//myhaspl  
ssize_t readn(int fd,void *ptr,size_t maxcn){//读取n个字符,maxc为读取的数目  
    size_t noreadcn,readcn;  
    char *buf=ptr;  
      
      
    noreadcn=maxcn;  
    while(noreadcn>0){  
       if ( (readcn=read(fd,buf,noreadcn))<0){//读数据  
      
          if (errno==EINTR) {//数据读取前，操作被信号中断 myhaspl  
             perror("中断错误");  
             readcn=0;              
          }  
          else {return -1;}//无法修复错误，返回读取失败  
       }  
       else if(readcn==0) break;//EOF myhaspl  
             
       noreadcn-=readcn;//读取成功，但是如果读取的字符数小于maxc，则继续读，因为可能数据还会继续通过网络送过来      
       buf+=readcn;     
        if (*buf==0) break;    //如果读到字符串结尾标志则退出，必须有这句，否则会死循环  myhaspl  
       }     
  
    return (maxcn-noreadcn);  
}  
  
ssize_t writen(int fd,void *ptr,size_t maxcn){//写入n个字符  
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
    struct sockaddr_in address;//地址信息结构 myhaspl  
    int pid;  
    char mybuf[100];          
    char *buf="myhaspl\n";  
    int rc;  
    
    fd=socket(AF_INET,SOCK_STREAM,0);//建立socket  
    if (fd==-1){//错误，类型从errno获得  
        perror("error");//perror先输出参数，后跟":"加空格，然后是errno值对应的错误信息(不是错误代码)，最后是一个换行符。    myhaspl       
    }  
     printf("client send....\n");  
    fflush(stdout);  
      
    //连接  
    address.sin_family=AF_INET;//IPV4协议,AF_INET6是IPV6 myhaspl  
    address.sin_addr.s_addr=inet_addr("127.0.0.1");//l表示32位，htonl能保证在不同CPU的相同字节序  
    address.sin_port=htons(1253);//端口号，s表示16位 myhaspl  
    addresslen=sizeof(address);          
    rc=connect(fd,(struct sockaddr *)&address,addresslen);//连接服务器 myhaspl  
    if (rc==-1){//rc=0成功，rc=-1失败 myhaspl  
      perror("连接错误");  
      exit(1);  
    }  
    //发送数据   
    writen(fd,(void *)buf,strlen(buf)+1);  
    printf("client send :%s\n",buf);        
    //读取数据  
    bzero(mybuf,100);    
    readn(fd,(void *)mybuf,100);   
    printf("client read :%s\n",mybuf);   
    close(fd);  
    exit(0);                  
   }  
