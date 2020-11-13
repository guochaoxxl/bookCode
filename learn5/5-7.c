#include <glib-2.0/glib.h>
#include <stdio.h>
#include <locale.h>
int main(int argc, char *argv[]){
	setlocale(LC_ALL,"");
	GRand *gamerand;
	gchar gamename[10];
	g_print("您叫什么名字?\n");
	scanf("%s",&gamename);
	g_print("欢迎您，%s,这里是21点游戏\n",gamename);
	g_print("%s,请按键抽数字！\n",gamename);
	getchar();
	getchar();
	gint rndnumber;
	gamerand = g_rand_new();	
	rndnumber=g_rand_int_range(gamerand,1,11);
	g_print("%s,您抽到的是：%d\n",gamename,rndnumber);
	g_rand_free(gamerand);
	return 0;
}

