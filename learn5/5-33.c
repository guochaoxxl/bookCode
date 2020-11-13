#include <locale.h>
#include <stdio.h>
#include <panel.h>
#include <ncursesw/ncurses.h>
//code by myhaspl@myhaspl.com
//date:2014/1/17
int isExist(char *filename)
{
         return (access(filename, 0) == 0);
}
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
        mvprintw(3,COLS/2-10,"简单编辑器-仅限于单个屏幕的编辑");
        mvprintw(4,COLS/2-20,"【F9读保存内容，F10存盘，F11退出，F12删除整行,TAB换窗口】");
        refresh();
        init_pair(1, COLOR_GREEN, COLOR_BLACK);
        init_pair(2, COLOR_BLUE, COLOR_BLACK);
       	init_pair(3, COLOR_RED,COLOR_BLACK); 
	WINDOW *mywins[3];
	PANEL *top;
       	PANEL *mypanels[3];
	char filename[10];
        int width=COLS-18;
        int height=LINES-18;
        int x,y;
	int begin_y=5;int begin_x=5;
	int i;
	for(i = 0; i < 3; ++i)
	{
	        mywins[i]=newwin(height,width,begin_y,begin_x);//新窗口(行，列,begin_y,begin_x)
       	        keypad(mywins[i],TRUE);
	        wattron(mywins[i],COLOR_PAIR(i+1));
		mypanels[i] = new_panel(mywins[i]);
		box(mywins[i],ACS_VLINE,ACS_HLINE);
	        wattroff(mywins[i],COLOR_PAIR(i+1));
		begin_y+=4;begin_x+=4;
	}
	set_panel_userptr(mypanels[0],mypanels[1]);
	set_panel_userptr(mypanels[1],mypanels[2]);
	set_panel_userptr(mypanels[2],mypanels[0]);
	top = mypanels[2];
	update_panels();
	doupdate();
	int nowwinid=2;
	sprintf(filename,"myed%d.dat",nowwinid);
	getyx(mywins[nowwinid],y,x);
       	++y;++x;
        mmask_t oldmousemask;
        int ans=0;
        FILE *fp2=NULL;
        FILE *fp1=NULL;
        mousemask(ALL_MOUSE_EVENTS, &oldmousemask);
        while(1){
                int c=mvwgetch(mywins[nowwinid],y,x);
                switch(c)
                {       case KEY_MOUSE:
                        if(getmouse(&event) == OK)
                        {       /* When the user clicks left mouse button */
                                if(event.bstate & BUTTON1_PRESSED)
                                {
                                                y=event.y-7;x=event.x-7;
                                                wmove(mywins[nowwinid],y,x);
                                }

                        }
                        break;
                        case KEY_BACKSPACE:
                                --x;
                                if (x<1){
                                        --y;x=width-2;
                                }
                                if (y<1){
                                        y=height-2;
                                }
                                mvwprintw(mywins[nowwinid],y,x," ");
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
                        case KEY_F(11):
                                //退出
                                mvprintw(LINES-3,2,"                     ");
                                mvprintw(LINES-3,2,"退出编辑器吗？     ");
                                mvprintw(LINES-2,2,"    ");
                                mvprintw(LINES-1,2,"     \n");
                                refresh();
                                ans=getch();
                                if (ans=='Y' ||ans=='y')
                                {
                                        mvprintw(LINES-2,2,"是\n");
                                        refresh();
                                        wattroff(mywins[nowwinid],COLOR_PAIR(1));
                                        mousemask(oldmousemask,NULL);
                                        endwin();
                                        return 0;
                                }else
                                        mvprintw(LINES-2,2,"否\n");
                                        refresh();
                                break;

			case 9:
				top = (PANEL *)panel_userptr(top);
				top_panel(top);
				update_panels();
				doupdate();
				nowwinid=(++nowwinid)%3;
				sprintf(filename,"myed%d.dat",nowwinid);
				break;
                        case KEY_F(10):
                                //存盘
                                mvprintw(LINES-3,2,"                     ");
                                mvprintw(LINES-3,2,"保存当前内容吗？     ");
                                mvprintw(LINES-2,2,"    ");
                                mvprintw(LINES-1,2,"     \n");
                                refresh();
                                ans=getch();
                                if (ans=='Y' ||ans=='y')
                                {
                                        mvprintw(LINES-3,2,"                     ");
                                        fp1 = fopen(filename,"wb");
                                        if (fp1!=NULL){
                                                int jg= putwin(mywins[nowwinid],fp1);
                                                fclose(fp1);
                                                if (jg==OK)  mvprintw(LINES-1,2,"保存成功!\n");
                                        }
                                        mvprintw(LINES-3,2,"保存当前内容吗？     ");
                                        mvprintw(LINES-2,2,"是\n");
                                        refresh();
                                }else
                                        mvprintw(LINES-2,2,"否\n");
                                        refresh();
                                break;
                        case KEY_F(9):
                                //读取存盘
                                mvprintw(LINES-3,2,"                    ");
                                mvprintw(LINES-3,2,"读取保存内容吗？    ");
                                mvprintw(LINES-2,2,"    ");
                                mvprintw(LINES-1,2,"     \n");
                                refresh();
                                ans=getch();
                                if (ans=='Y' ||ans=='y')
                                {
                                        if (isExist(filename)) {
                                        fp2 = fopen(filename,"rb");
                                        if (fp2!=NULL){
                                                WINDOW *newwin=getwin(fp2);
                                                if (newwin!=NULL) {
                                                        WINDOW *temp=mywins[nowwinid];
                                                        mywins[nowwinid]=newwin;
							delwin(temp);
							PANEL *temppan=mypanels[nowwinid];
							mypanels[nowwinid] = new_panel(mywins[nowwinid]);
							del_panel(temppan);
							set_panel_userptr(mypanels[0],mypanels[1]);
							set_panel_userptr(mypanels[1],mypanels[2]);
							set_panel_userptr(mypanels[2],mypanels[0]);
							top = mypanels[nowwinid];
							top_panel(top);
							update_panels();
							doupdate();
                            mvprintw(LINES-1,2,"读取成功!\n");
                                           }
                                                fclose(fp2);
                                        }
                                        }

                                      mvprintw(LINES-3,2,"读取保存内容吗？    ");
                                      mvprintw(LINES-2,2,"是\n");
                                      refresh();
                                }else
                                      mvprintw(LINES-2,2,"否\n");
                                      refresh();
                                break;
                        case KEY_F(12):
                                //删除某行
                                wdeleteln(mywins[nowwinid]);
                                winsertln(mywins[nowwinid]);
                                box(mywins[nowwinid],ACS_VLINE,ACS_HLINE);
                                break;
                        case KEY_DC:
                                //删除某字符
                                mvwprintw(mywins[nowwinid],y,x," ");
                                break;
                        default:
                                mvwprintw(mywins[nowwinid],y,x,"%c",c);
                                ++x;
                                if (x>=width-1){
                                        ++y;
                                        x=1;
                                }
                                if (y>=height-1){
                                        y=1;
                                }
				doupdate();
                }
        }
	return 0;
}
