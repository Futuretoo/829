#include <stdio.h>
/*
指针指向字符串
以及指针数组
*/
void main3() {
	void change1(char *s);
	void sort(char *s[],int n);
	void print(char *s[],int n);

	char string1[]= {"I love China!"};
	char *string2 = "I love Japan!";
	char *countries[]= {"France","Australia","Canada","Italy","China","Cuba"};

	change1(string2);

	sort(countries,6);
	print(countries,6);
}

//这种方式只能改变指针的指向，即再次赋值；不能单独改变某一位字符
void change1(char *s) {
//	*(s+5) = '#';//这么做是无用的，且运行报错
	printf("%s\n",s);//这里是s，不是*s
	s = "I hate Japan!";
	printf("%s\n",s);


}

//对字符串数组排序
void sort(char *s[],int n) {
	char *temp;
	int i,j,k;
	for(i=0; i<n-1; i++) {
		k=i;
		//选择法排序 
		for(j=i+1; j<n; j++) {
			if(strcmp(s[k],s[j])>0)
				k=j;//选出最小的 
		}
		if(k!=i) {
			temp=s[i];
			s[i]=s[k];
			s[k]=temp;
		}
	}
}

void print(char *s[],int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%s\n",s[i]);
	}
}




