#include <ncurses.h>
int main(void){
    initscr();//��ʼ��
    box(stdscr,ACS_VLINE,ACS_HLINE);//���߿�
    mvaddstr(15,2,"hello,world");//��15,2��ʾ�ַ���
    refresh();//ˢ����Ļ
    getch();//�ȴ�����
    endwin();//����
    return 0;    
}

