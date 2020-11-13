#include <ncursesw/ncurses.h>  
#include <locale.h> 
int main(void){ 
    int y,x,i,j,h,w;
    setlocale(LC_ALL,""); 
    WINDOW *pad; 
    initscr();//初始化 
    getmaxyx(stdscr,h,w);//获得屏幕尺寸 
    //画背景
    for(i=0;i<h;i++){
         for(j=0;j<w;j++){
             mvaddch(i,j,ACS_CKBOARD);
         }
    }
    refresh();
    //建立窗口
    pad=newpad(80,90);
    for (i=0;i<80;i++){
        char line[90];
        sprintf(line,"line %d\n",i);
        mvwprintw(pad,i,1,line);
    }
    refresh();
    prefresh(pad,0,1,5,10,20,25);//刷新pad。0,1  为基垫需要显示区域的左上角置(行列对，以下同此)。5,10,20,45为屏幕显示区域的左上角和右下角位置
    for(i=0;i<65;i++){
        prefresh(pad,i+1,1,5,10,20,25);//刷新pad，实现流屏;
        usleep(30000); 
    }
    getch();//等待按键
    delwin(pad); 
    endwin();//结束 
    return 0;    
} 

