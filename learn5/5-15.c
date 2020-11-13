#include <ncurses.h>
int main(void){
    initscr();//初始化
    box(stdscr,ACS_VLINE,ACS_HLINE);//画边框
    mvaddstr(15,2,"hello,world");//在15,2显示字符串
    refresh();//刷新屏幕
    getch();//等待按键
    endwin();//结束
    return 0;    
}

