#include <ncursesw/ncurses.h>  
#include <locale.h> 
int main(void){ 
    int y,x,i,j,h,w;
    setlocale(LC_ALL,""); 
    WINDOW *pad; 
    initscr();//��ʼ�� 
    getmaxyx(stdscr,h,w);//�����Ļ�ߴ� 
    //������
    for(i=0;i<h;i++){
         for(j=0;j<w;j++){
             mvaddch(i,j,ACS_CKBOARD);
         }
    }
    refresh();
    //��������
    pad=newpad(80,90);
    for (i=0;i<80;i++){
        char line[90];
        sprintf(line,"line %d\n",i);
        mvwprintw(pad,i,1,line);
    }
    refresh();
    prefresh(pad,0,1,5,10,20,25);//ˢ��pad��0,1  Ϊ������Ҫ��ʾ��������Ͻ���(���жԣ�����ͬ��)��5,10,20,45Ϊ��Ļ��ʾ��������ϽǺ����½�λ��
    for(i=0;i<65;i++){
        prefresh(pad,i+1,1,5,10,20,25);//ˢ��pad��ʵ������;
        usleep(30000); 
    }
    getch();//�ȴ�����
    delwin(pad); 
    endwin();//���� 
    return 0;    
} 

