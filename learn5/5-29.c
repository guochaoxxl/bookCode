#include <locale.h>
#include <stdio.h>
#include <ncursesw/ncurses.h>
//code by myhaspl@myhaspl.com
//date:2014/1/17
int main(int argc, char *argv[])
{
	MEVENT event;
	setlocale(LC_ALL,"");
	initscr();
	clear();
	noecho();
	cbreak();
	if(has_colors() == FALSE)
	{ 
	   endwin();
	   printf("你的终端不支持色彩！\n");
	   return (1);
	}
	start_color(); /*启动color 机制*/
	mvprintw(5,COLS/2-10,"简单编辑器-仅限于单个屏幕的编辑");
	refresh();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	WINDOW *win1;  
	int width=COLS-14;
    int height=LINES-14;
    int x,y;
    win1=newwin(height,width,7,7);//新窗口(行，列,begin_y,begin_x)
	keypad(win1,TRUE);
    wattron(win1,COLOR_PAIR(1));	
    box(win1,ACS_VLINE,ACS_HLINE);
	wrefresh(win1);
	getyx(win1,y,x);
	++y;++x;
	mmask_t oldmousemask;
	mousemask(ALL_MOUSE_EVENTS, &oldmousemask);
	while(1){
		int c=mvwgetch(win1,y,x);
		switch(c)
		{	case KEY_MOUSE:
			if(getmouse(&event) == OK)
			{	/* When the user clicks left mouse button */
				if(event.bstate & BUTTON1_PRESSED)
				{
						y=event.y-7;x=event.x-7;
						wmove(win1,y,x);
				}

			}
			break;
			case KEY_RIGHT:
				++x;
				if (x>=width-1) {
					++y;
					x=1;
				}
				break;
			case KEY_LEFT: --x;
				if (x<1){
					--y;
					x=width-2;
				}
				break;
			case KEY_UP:
			       	--y;
				if (y<1){
					y=height-2;
				}
				break;
			case KEY_DOWN:
			       	++y;
				if (y>=height-1){
					y=1;
				}
				break;
			case 10:
			       	++y;
				if (y>=height-1){
					y=1;
				}
				break;
			case KEY_F(1):
			       	//退出
				mvprintw(LINES-3,2,"退出编辑器吗？");
				mvprintw(LINES-2,2,"    ");
				refresh();
				int ans=getch();
				if (ans=='Y' ||ans=='y')
				{
					mvprintw(LINES-2,2,"是\n");
                    refresh();
                    wattroff(win1,COLOR_PAIR(1));
     				mousemask(oldmousemask,NULL);
                    delwin(win1);
                    endwin();
                    return 0;
				}else
					mvprintw(LINES-2,2,"否\n");
					refresh();
				break;
			case KEY_F(12):
			       	//删除某行
				wdeleteln(win1);
				winsertln(win1);
        			box(win1,ACS_VLINE,ACS_HLINE);
			case KEY_DC:
			       	//删除某字符
       		        	mvwprintw(win1,y,x," ");
				break;
			default:
       		        	mvwprintw(win1,y,x,"%c",c);
				++x;
				if (x>=width-1){
			      	 	++y;
					x=1;
				}		
				if (y>=height-1){
					y=1;
				}
				wrefresh(win1);
		}
	}
    wattroff(win1,COLOR_PAIR(1));	
	endwin();
	mousemask(oldmousemask,NULL);
	return 0;
}
