#include <locale.h>
#include <stdio.h>
#include <ncursesw/ncurses.h>
int main(int argc, char *argv[])
{
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
        box(win1,ACS_VLINE,ACS_HLINE);
        wattron(win1,COLOR_PAIR(1));	
	wrefresh(win1);
	getyx(win1,y,x);
	++y;++x;
	while(1){
		int c=mvwgetch(win1,y,x);
		switch(c)
		{
			case KEY_RIGHT:
				++x;
				if (x>=width-1) {
					++y;
					x=1;
				}
				break;
			case KEY_LEFT:
				--x;
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
	return 0;
}
