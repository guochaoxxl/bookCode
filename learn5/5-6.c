#include <glib-2.0/glib.h>
#include <stdio.h>
#include <locale.h>
int main(int argc, char *argv[]){
	setlocale(LC_ALL,"");
	gchar gamename[10];
	g_print("����ʲô����?\n");
	scanf("%s",&gamename);
	g_print("��ӭ����%s,������21����Ϸ\n",gamename);
	return 0;
}

