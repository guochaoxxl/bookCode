#include <glib-2.0/glib.h>
#include <stdio.h>
#include <locale.h>
int main(int argc, char *argv[]){
	setlocale(LC_ALL,"");
	GRand *gamerand;
	gchar gamename[10];
	g_print("����ʲô����?\n");
	scanf("%s",&gamename);
	g_print("��ӭ����%s,������21����Ϸ\n",gamename);
	g_print("%s,�밴�������֣�\n",gamename);
	getchar();
	getchar();
	gint rndnumber;
	gamerand = g_rand_new();	
	rndnumber=g_rand_int_range(gamerand,1,11);
	g_print("%s,���鵽���ǣ�%d\n",gamename,rndnumber);
	g_rand_free(gamerand);
	return 0;
}

