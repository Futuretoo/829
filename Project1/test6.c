#include<stdio.h>
#include<string.h>
/*
字符串长度 
*/
void main() {
	char *s="you are beautiful\0 it is true";
	printf("%s\n",s);//you are beautiful,截取到\0 
	//sizeof是关键字 
	printf("%d\n",sizeof(*s));//1
	printf("%d\n",sizeof(s));//32位系统为4，64位系统为8；char的分配空间大小 
	printf("%d\n",sizeof("you are beautiful\0 it is true"));//30，总长度 
	//strlen是函数 
	printf("%d\n",strlen("you are beautiful\0 it is true"));//17,截取到\0 
}
