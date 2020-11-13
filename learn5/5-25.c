#include <ncursesw/ncurses.h>
#include <locale.h>
int main(){
//init_pair(short index,short foreground,short background)初始化颜色索引
//attron(COLOR_PAIR(索引号)|属性)
//newwin建立窗口,derwin建立窗口的子窗口(相对于父窗口相对位置)，subwin建立窗口的子窗口(相对于根窗口绝对位置)
    setlocale(LC_ALL,"");
    char mesg[]="您的名字:"; /* 将要被打印的字符串信息*/
    char name[80];
    int y,x;
    initscr();//初始化
    mvprintw(1,1,"WIN1");
    mvprintw(2,1,"您好");
    mvprintw(3,1,"%s",mesg);
    getyx(stdscr, y, x);
    move((y+2),2);
    attron(A_REVERSE);
    printw("*********************");
    refresh();
    attroff(A_REVERSE);
    getyx(stdscr, y, x);
    move((y-1),1);
    scanw("%s",name); 
    mvprintw(6,1,"%s好，很高兴认识您", name);
    refresh();
    endwin();//结束
    return 0;   
}
