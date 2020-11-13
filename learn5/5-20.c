#include <ncursesw/ncurses.h>
#include <locale.h> 
int main(void){ 
//init_pair(short index,short foreground,short background)初始化颜色索引 
//attron(COLOR_PAIR(索引号)|属性) 
//newwin建立窗口,derwin建立窗口的子窗口(相对于父窗口相对位置)，subwin建立窗的子窗口(相对于根窗口绝对位置) 
    int x,y;
    setlocale(LC_ALL,""); 
    WINDOW *win1,*win2,*subwin; 
    initscr();//初始化 
    win1=newwin(15,50,1,1);//新窗口(行，列,begin_y,begin_x) 
    box(win1,ACS_VLINE,ACS_HLINE); 
    mvwprintw(win1,1,1,"WIN1"); 
    mvwprintw(win1,2,1,"myhaspl@myhaspl.com"); 
    win2=newwin(10,40,10,30);//新窗口(行，列,begin_y,begin_x) 
    box(win2,ACS_VLINE,ACS_HLINE); 
    wmove(win2,1,1);//移动某窗口的光标
    printw("WIN2");
    wmove(win2,2,1);//移动某窗口的光标。(窗口,y,x)
    printw("myhaspl@myhaspl.com"); 

    subwin=derwin(win2,3,20,4,5); //子窗口 

    box(subwin,ACS_VLINE,ACS_HLINE); 
    mvwprintw(subwin,1,5,"按任意键退出");//(窗口，y,x,字符串) 
       
    refresh();//刷新整个大窗口stdscr 
    wrefresh(win1); 
    wrefresh(win2); 
    
    move(5,60);//在stdscr移动光标
    printw("hello.........");
    touchwin(win1);//转换当前窗口为win1 
    wrefresh(win1); 
    getch();//win1显示完，等待按键显示win2 

    touchwin(win2);//转换当前窗口为win2  
    //使用doupdate,可以事先定义要刷新的部分，然后刷新 
    wnoutrefresh(win2);   
    wnoutrefresh(subwin); 
    doupdate(); 
    getyx(subwin,y,x);//获得当前逻辑光标位置
    mvwprintw(subwin,y+1,x,"................");//在“按任意键退出"下一行输出"..............."
    getch();//等待按键 
    delwin(win1); 
    delwin(subwin); 
    delwin(win2); 
    endwin();//结束 
    return 0;    
} 

