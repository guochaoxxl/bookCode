#include <glib-2.0/glib.h>
#include <locale.h>
#include <string.h>
//code:myhaspl@myhaspl.com
//date:2014-01-27
struct gab_var{
	gpointer var;
	int count;
};
struct gab_collect{
	GHashTable *gab_table;
        int gab_count;	
};
typedef struct gab_var GabVar;
typedef struct gab_collect GabCollect;
void varvalcol(gpointer valdata){
//变量列表删除的相关清理工作，在g_hash_table_foreach_remove函数删除某个key/value对时，自动调用。
	g_printf("\ndelete: %s\n",(gchar*)(((GabVar*)valdata)->var));
	g_free(valdata);
	}
GabCollect *init_gabcollect(){
	gpointer mygab=g_malloc0(sizeof(GabCollect));
	((GabCollect*)mygab)->gab_table=g_hash_table_new_full(g_str_hash,g_str_equal,NULL,varvalcol);
	return (GabCollect*)mygab;
}
void newvar(gchar *mystr,GabCollect *varlist,gpointer myvar){
	GabVar *gabvar=g_malloc0(sizeof(GabVar));
	gabvar->var=myvar;
	gabvar->count=1;
	g_hash_table_insert(varlist->gab_table,mystr,gabvar);		
	varlist->gab_count+=1;
}
void getvar(gchar *mystr,GabCollect *varlist,gpointer myvar){
//访问变量
	gpointer tmpvar=g_hash_table_lookup(varlist->gab_table,mystr);
	if (tmpvar==NULL){
	       	newvar(mystr,varlist,myvar);		
	}else{
		((GabVar*)tmpvar)->count+=1;
	}
}
void endvar(gchar *mystr,GabCollect *varlist){
//访问完毕变量
	gpointer tmpvar=g_hash_table_lookup(varlist->gab_table,mystr);
	if (tmpvar!=NULL){
		((GabVar*)tmpvar)->count-=1;
	}
}
gboolean gabvarcol(gpointer key,gpointer var,gpointer user_data){
	if (((GabVar*)var)->count<=0){
		return TRUE;
	}else{
		return FALSE;
	}
}
void gab_col(GabCollect *varlist){
	//轮询清理变量列表，查找引用数为0的变量，然后删除。
	g_hash_table_foreach_remove(varlist->gab_table,gabvarcol,NULL);	
}
gchar* newstr(gchar *mystr){
       gchar* tmpchar=g_strdup(mystr);	
       return tmpchar;
}
void end_gabcollect(GabCollect *mygab){
	gab_col(mygab);
	g_hash_table_unref(mygab->gab_table);
	g_free(mygab);
}
int main(){
	GabCollect *var_list=init_gabcollect();	
    gchar* str1=newstr("hello,");
    gchar* str2=newstr("world\n");
	
	getvar("str1",var_list,str1);
	getvar("str2",var_list,str2);
	getvar("str1",var_list,str1);
	g_printf(str1);
	g_printf(str2);
	endvar("str2",var_list);
	endvar("str1",var_list);

	gab_col(var_list);
	
	g_printf(str1);
	endvar("str1",var_list);
    end_gabcollect(var_list);	
}

