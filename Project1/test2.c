#include <stdio.h>

/*
构造一个学生成绩的二维数组，打印符合要求的学生的成绩
*/
int row=3;//行号，代表几个学生
int col=4;//列号，代表几门成绩
float grade[3][4]= {{56.3,67.5,45.6,96.9}, {70.5,34.6,67.8,66.5}, {66.6,67.9,89.5,59.9}};

void main() {
	void printOne1(float *a);
	void printOne2(float a[][4],int n);
	void printOne3(float (*a)[4],int n);

	//grade[2][1]
	printf("grade%d : %.2f\n\n\n",1,*(*(grade+2)+1));

	//
	printf("method1\n");
	printOne1(grade+1);
	printf("\n");

	//
	printf("method2\n");
	printOne2(grade,1);

	//
	printf("method3\n");
	printOne3(grade,1);
}

//打印某个学生的所有成绩，
//传入某行的首地址，用指针遍历
void printOne1(float *a) {
	float *p;
	int i=0;
	//传入二维数组，则a指向grade[0]，a是普通float指针 
	//p=a,则p指向grade[0][0]，p是普通float指针 
	for(p=a; i<col; i++) {
		printf("grade%d : %.2f\n",i,*(p+i));
//		printf("grade%d : %.2f\n",i,*(a+i));//p++，a++相同，因为传入的时候已经转化了 
	}
}

//打印某个学生的所有成绩
//传入整个数组和行号
void printOne2(float a[][4],int n) {
	int i;
	for(i=0; i<col; i++) {
		printf("grade%d : %.2f\n",i,a[n][i]);
	}
}

//打印某个学生的所有成绩，
//以指针传入整个数组和行号
void printOne3(float (*a)[4],int n) {
	//float (*a)[4] 代表是一个指针，指向一个含4个float元素的数组的首地址 
	//如果传入二维数组的指针，则指向二维数组首行的首地址grade[0]，a现在是行指针 
	int i;
	for(i=0; i<col; i++) {
		printf("grade%d : %.2f\n",i,*(*(a+n)+i));
	}
}














