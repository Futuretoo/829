#include<stdio.h>
#include<string.h>
/*
字符串
*/
void main6() {
	char *s="you are beautiful,\0 it is true";
	printf("%s\n",s);//you are beautiful,截取到\0
	//sizeof是关键字
	printf("%d\n",sizeof(*s));//1
	printf("%d\n",sizeof(s));//32位系统为4，64位系统为8；char的分配空间大小
	printf("%d\n",sizeof("you are beautiful,\0 it is true"));//31，总长度
	//strlen是函数
	printf("%d\n",strlen("you are beautiful,\0 it is true"));//18,截取到\0
//////////////////////////////////////////////////////////////
	printf("********************************\n");
	//strcat 把s2拼接到s1后面，并返回s1
	//s1必须是数组形式
	char *s1="you are beautiful,\0 it is true";
	char *s2="Sherry";
	char s3[]= {"you are beautiful,\0 it is true"};
	char s4[3]="s\0!";
	char s5[20]="Sherry\0Sherry";
//	printf("%s",strcat(s1,s2));//这种是错误的，第一个str必须是数组形式，即必须有余留的位置，且余留的位置必须大于要拼接的字符串
	printf("%s\n",strcat(s3,s2));// "you are beautiful,Sherry\0"

	//这里可见，不是新生成一个字符串返回，就是直接拼接在s1后面
	printf("%s\n",s3);//"you are beautiful,Sherry\0"
	int i;
	for(i=0; i<sizeof(s3); i++) {
		putchar(s3[i]);
	}
	//"you are beautiful,Sherry\0 true\0"
	putchar('\n');

//////////////////////////////////////////////////////////////
	printf("********************************\n");
	//strcpy 把s2复制到s1，并返回s1
	//s2会从s1的起始位置开始覆盖，直到遇到s2的第一个\0,s1后面的不覆盖
	printf("%s\n",strcpy(s3,s2));//"Sherry\0"
	for(i=0; i<sizeof(s3); i++) {
		putchar(s3[i]);
	}
	//"you are beautiful,Sherry\0 true\0"
	putchar('\n');

	//这里说明s2也是截取到第一个\0处
	printf("%s\n",strcpy(s3,s5));//"Sherry\0"
	for(i=0; i<sizeof(s3); i++) {
		putchar(s3[i]);
	}
	//"you are beautiful,Sherry\0 true\0"
	putchar('\n');

	//这两个打印为什么不一样？？？？？ 
	printf("%s\n",strcpy(s4,s5));//"Sherry\0"
	for(i=0; i<sizeof(s4); i++) {
		putchar(s4[i]);
	}
	putchar('?');//"Sher?"//注意！这里没有结尾的\0了，所有的位置都用来接纳s2

}













