#include <ncursesw/ncurses.h>
#include <locale.h>
int main(){
//init_pair(short index,short foreground,short background)初始化颜色索引
//attron(COLOR_PAIR(索引号)|属性)
//newwin建立窗口,derwin建立窗口的子窗口(相对于父窗口相对位置)，subwin建立窗口的子窗口(相对于根窗口绝对位置)
    setlocale(LC_ALL,"");
    char mesg[]="您的名字:"; /* 将要被打印的字符串信息*/
    char name[80];
    WINDOW *win1;
    initscr();//初始化
    win1=newwin(15,50,1,1);//新窗口(行，列,begin_y,begin_x)
    box(win1,ACS_VLINE,ACS_HLINE);
    mvwprintw(win1,1,1,"WIN1");
    mvwprintw(win1,2,1,"您好");
    mvwprintw(win1,3,1,"%s",mesg);
    wscanw(win1,"%s",name);
    mvwprintw(win1,5,1,"%s好，很高兴认识您", name);
    wrefresh(win1);
    endwin();//结束
    return 0;
}
