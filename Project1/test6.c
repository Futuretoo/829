#include<stdio.h>
#include<string.h>
/*
�ַ������� 
*/
void main() {
	char *s="you are beautiful\0 it is true";
	printf("%s\n",s);//you are beautiful,��ȡ��\0 
	//sizeof�ǹؼ��� 
	printf("%d\n",sizeof(*s));//1
	printf("%d\n",sizeof(s));//32λϵͳΪ4��64λϵͳΪ8��char�ķ���ռ��С 
	printf("%d\n",sizeof("you are beautiful\0 it is true"));//30���ܳ��� 
	//strlen�Ǻ��� 
	printf("%d\n",strlen("you are beautiful\0 it is true"));//17,��ȡ��\0 
}
