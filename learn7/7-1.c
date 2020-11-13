#include <stdio.h>
#include <sys/wait.h>
#define MAXLINE 100
//execlp模拟SHELL
int main(void){
   int pid;
   int jg,status,len;
   char buf[MAXLINE];
   printf("\n##myhaspl~~");//自定义的shell提示符
   while(fgets(buf,MAXLINE,stdin)!=NULL){//读入一行
        len=strlen(buf)-1;
        if (buf[len]=='\n'){        //去除换行符,execlp只接受以NULL结尾
            buf[len]=0;            
        }
        pid=fork();
        if (pid<0){
           printf("fork error!\n");
        }
        else if (pid==0){//子进程
           printf("\n");        
           if (buf[0]=='Q'&&strlen(buf)==1){//键入Q表示退出shell          
               exit(200); 
           }
           jg=execlp(buf,buf,(char *)0);
           if (jg==-1){//错误
              printf("不能执行:%s\n",buf);    
              exit(127);          
           }              
              exit(0);       
        }
		else{//父进程
          if ((jg==waitpid(pid,&status,0))<0){
            printf("waitpid error\n");
          }
          if (WEXITSTATUS(status)==200) {//WEXITSTATUS计算返回值
                printf("退出....\n");  
                break;          
          }
        printf("\n##myhaspl~~");//自定义的shell提示符
		}
   }
exit(0);
}
