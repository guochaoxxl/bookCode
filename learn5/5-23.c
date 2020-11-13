#include <locale.h>
#include <ncursesw/ncurses.h>
#include <string.h>
int main()
{
char mess[]="您的性别:"; /* 将要被打印的字符串信息*/
char mesg[]="您的名字:"; /* 将要被打印的字符串信息*/
char name[80];
char sex[10];
int row,col; /* 存储行号和列号的变量，用于指定光标位置*/
setlocale(LC_ALL,"");
initscr(); /* 进入curses 模式*/
getmaxyx(stdscr,row,col); /* 取得stdscr 的行数和列数*/
mvprintw(row/2,col/2-strlen(mesg),"%s",mesg); /* 在屏幕的正中打印字符串mesg */
getstr(name); /* 将指针name 指向读取的字符串*/
mvprintw(row/3,col/2-strlen(mess),"%s",mess); /* 在屏幕的正中打印字符串mesg */
getstr(sex); /* 将指针sex向读取的字符串*/
char man[]="man";
if (strcmp(sex,man)==0) {
	mvprintw(LINES-2,0, "%s先生好，很高兴认识您", name);//LINES为当前行数
}
else
{
	mvprintw(LINES-2,0, "%s女士好，很高兴认识您", name);//LINES为当前行数
}
refresh();
getch();
endwin();
return 0;
}
