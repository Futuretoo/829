#include<stdio.h>
#include<string.h>
/*
�ַ���
*/
void main6() {
	char *s="you are beautiful,\0 it is true";
	printf("%s\n",s);//you are beautiful,��ȡ��\0
	//sizeof�ǹؼ���
	printf("%d\n",sizeof(*s));//1
	printf("%d\n",sizeof(s));//32λϵͳΪ4��64λϵͳΪ8��char�ķ���ռ��С
	printf("%d\n",sizeof("you are beautiful,\0 it is true"));//31���ܳ���
	//strlen�Ǻ���
	printf("%d\n",strlen("you are beautiful,\0 it is true"));//18,��ȡ��\0
//////////////////////////////////////////////////////////////
	printf("********************************\n");
	//strcat ��s2ƴ�ӵ�s1���棬������s1
	//s1������������ʽ
	char *s1="you are beautiful,\0 it is true";
	char *s2="Sherry";
	char s3[]= {"you are beautiful,\0 it is true"};
	char s4[3]="s\0!";
	char s5[20]="Sherry\0Sherry";
//	printf("%s",strcat(s1,s2));//�����Ǵ���ģ���һ��str������������ʽ����������������λ�ã���������λ�ñ������Ҫƴ�ӵ��ַ���
	printf("%s\n",strcat(s3,s2));// "you are beautiful,Sherry\0"

	//����ɼ�������������һ���ַ������أ�����ֱ��ƴ����s1����
	printf("%s\n",s3);//"you are beautiful,Sherry\0"
	int i;
	for(i=0; i<sizeof(s3); i++) {
		putchar(s3[i]);
	}
	//"you are beautiful,Sherry\0 true\0"
	putchar('\n');

//////////////////////////////////////////////////////////////
	printf("********************************\n");
	//strcpy ��s2���Ƶ�s1��������s1
	//s2���s1����ʼλ�ÿ�ʼ���ǣ�ֱ������s2�ĵ�һ��\0,s1����Ĳ�����
	printf("%s\n",strcpy(s3,s2));//"Sherry\0"
	for(i=0; i<sizeof(s3); i++) {
		putchar(s3[i]);
	}
	//"you are beautiful,Sherry\0 true\0"
	putchar('\n');

	//����˵��s2Ҳ�ǽ�ȡ����һ��\0��
	printf("%s\n",strcpy(s3,s5));//"Sherry\0"
	for(i=0; i<sizeof(s3); i++) {
		putchar(s3[i]);
	}
	//"you are beautiful,Sherry\0 true\0"
	putchar('\n');

	//��������ӡΪʲô��һ������������ 
	printf("%s\n",strcpy(s4,s5));//"Sherry\0"
	for(i=0; i<sizeof(s4); i++) {
		putchar(s4[i]);
	}
	putchar('?');//"Sher?"//ע�⣡����û�н�β��\0�ˣ����е�λ�ö���������s2

}













