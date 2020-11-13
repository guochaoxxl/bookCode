#include <glib-2.0/glib.h>
#include <stdio.h>
#include <locale.h>
int main(int argc, char *argv[]){
	setlocale(LC_ALL,"");
	gchar gamename[10];
	g_print("您叫什么名字?\n");
	scanf("%s",&gamename);
	g_print("欢迎您，%s,这里是21点游戏\n",gamename);
	return 0;
}

