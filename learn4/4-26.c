#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv){
        int exit_status=EXIT_SUCCESS;
        while (*++argv!=NULL)
        {
                //打开文件，如果出现错误，则显示错误信息
                FILE *output=fopen(*argv,"a");
                if (output==NULL){
                        perror(*argv);
                        exit_status=EXIT_FAILURE;
                        continue;
                }
                char mytext[500];
                int ch='\n';
                while (1){
                        printf("请输入文字：");
                        scanf("%s",&mytext);
                        if (strcmp(mytext,"%end%")!=0){
                                fputs(mytext,output);
                                //scanf函数不会读取换行符，因此加上换行符
                                fputc(ch,output);
                        }
                        else break;
                }
                if (fclose(output)!=0){
                        perror(*argv);
                        exit_status=EXIT_FAILURE;
                }

        }
        return exit_status;
}
