#include <panel.h>
#include <ncursesw/ncurses.h>
int main(int argc, char *argv[])
{
WINDOW *my_wins[3];
PANEL *my_panels[3];
int lines = 10, cols = 40, y = 2, x = 4, i;
initscr();
cbreak();
noecho();
/* 为每个面板创建窗口*/
my_wins[0] = newwin(lines, cols, y, x);
my_wins[1] = newwin(lines, cols, y + 1, x + 5);
my_wins[2] = newwin(lines, cols, y + 2, x + 10);
/* 为窗口添加创建边框以便你能看到面板的效果*/
for(i = 0; i < 3; ++i){
box(my_wins[i], 0, 0);
}
/* 按自底向上的顺序，为每一个面板关联一个窗口*/
my_panels[0] = new_panel(my_wins[0]);
/* 把面板0 压进栈, 叠放顺序: stdscr0
*/
my_panels[1] = new_panel(my_wins[1]);
/* 把面板1 压进栈, 叠放顺序: stdscr01
*/
my_panels[2] = new_panel(my_wins[2]);
/* 把面板2 压进栈, 叠放顺序: stdscr012*/
/* 更新栈的顺序。把面板2 置于栈顶*/
update_panels();
/* 在屏幕上显示*/
doupdate();
getch();
endwin();
}
