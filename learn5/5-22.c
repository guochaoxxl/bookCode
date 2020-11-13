#include <ncursesw/ncurses.h>
#include <ncurses.h>
#include <locale.h>
int main()
{
int ch;
setlocale(LC_ALL,"");
initscr(); /* 开始curses 模式*/
raw(); /* 禁用行缓冲*/
keypad(stdscr, TRUE); /* 开启功能键响应模式*/
noecho(); /* 当执行getch()函数的时候关闭键盘回显*/
printw("请按键！");
ch = getch(); /* 如果没有调用raw()函数，
我们必须按下enter 键才可以将字符传递给程序*/
if(ch == KEY_F(2)) /* 如果没有调用keypad（）初始化，将不会执行这条语句*/
printw("F2键按下！");
/* 如果没有使用noecho() 函数，一些控制字符将会被打印到屏幕上*/
else
{
  	printw("按键是:");
	attron(A_BOLD);
	printw("%c", ch);
	attroff(A_BOLD);
}
refresh(); /* 将缓冲区的内容打印到显示器上*/
getch(); /* 等待用户输入*/
endwin(); /* 结束curses 模式*/
return 0;
}
