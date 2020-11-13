#line 4 "6-16.c"  
#define LINUX  
#ifdef WIN32  
  printf("win32\n");     
#elif defined LINUX  
  printf("linux\n %d\n %s\n",__LINE__,__FILE__);          
#else  
  #error no flag define   
  //如果LINUX和WIN32没有定义，#error会显示错误信息，然后停止编译  
#endif  
}  
