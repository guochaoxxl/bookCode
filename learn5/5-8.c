#include <glib-2.0/glib.h>
#include <stdio.h>
#include <locale.h>
int main(int argc, char *argv[]){
	//��1����
	setlocale(LC_ALL,"");
	GRand *gamerand;
	gchar gamename[10];
	//��2����
	g_print("����ʲô����?\n");
	scanf("%s",&gamename);
	g_print("��ӭ����%s,������21����Ϸ\n",gamename);
	setbuf(stdin,NULL);
	//��3����
	gint key=0;
	gint rndnumber;
	gint man_number,comp_number;
	gint man_count=0,comp_count=0;
	gboolean man_end=FALSE,comp_end=FALSE;
	gboolean gameover=FALSE;
	gamerand = g_rand_new();	
	//��4����
	do{
		//4-1����
		//��ҳ�����
if (!man_end){
			g_print("%s,��Y/y��������,����������ʾ���ٳ�����!\n",gamename);
			key=getchar();
			getchar();
			//��ҳ�����
			if (key=='y'||key=='Y'){
				rndnumber=g_rand_int_range(gamerand,1,11);
				man_number=rndnumber;
				man_count+=man_number;
				g_print("%s,���鵽���ǣ�%d\n",gamename,man_number);
			}else
			{
				g_print("��ҷ�������!\n",comp_number);
				man_end=TRUE;
			}
	       	}
	    //4-2����
		//���Գ�����
		if (comp_count<=17){
			rndnumber=g_rand_int_range(gamerand,1,11);
			comp_number=rndnumber;
			comp_count+=comp_number;
			g_print("���Գ鵽���ǣ�%d\n",comp_number);
		}else
		{
			g_print("���Է�������!\n",comp_number);
			comp_end=TRUE;
		}
        //��5����
		if ((man_count>21 && comp_count>21)||(man_count<=21 && comp_count<=21 && man_count==comp_count && man_end &&comp_end)){
			g_print("ƽ��,����%d�㣬%s %d��\n",comp_count,gamename,man_count);
			gameover=TRUE; 
		}
		else if ((man_count>21 && comp_count<=21)||(man_count<21 && comp_count==21)) {
			g_print("����Ӯ��,����%d�㣬%s %d��\n",comp_count,gamename,man_count);
			gameover=TRUE; 
		}
		else if ((man_count<=21 && comp_count>21) ||(man_count==21 && comp_count<21)) {
			g_print("���Ӯ��,����%d�㣬%s %d��\n",comp_count,gamename,man_count);
			gameover=TRUE; 
		}
		else if (man_end && comp_end){
			  man_count>comp_count?g_print("���Ӯ��,����%d�㣬%s %d��\n",comp_count,gamename,man_count):g_print("����Ӯ��,����%d�㣬%s %d��\n",comp_count,gamename,man_count);
		      	  gameover=TRUE; 
		}
	}while(!gameover);
	g_rand_free(gamerand);
	return 0;
}

