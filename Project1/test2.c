#include <stdio.h>

/*
构造一个学生成绩的二维数组，打印符合要求的学生的成绩
*/
int row=3;//行号，代表几个学生
int col=4;//列号，代表几门成绩
float grade[3][4]= {{76.3,67.5,55.6,96.9}, {70.5,84.6,67.8,66.5}, {66.6,67.9,89.5,60.9}};

void main2() {
	void printOne1(float *a);
	void printOne2(float a[][4],int n);
	void printOne3(float (*a)[4],int n);
	void search1();
	void average();
	
//	//grade[2][1]
//	printf("grade%d : %.2f\n\n\n",1,*(*(grade+2)+1));
//
//	//
//	printf("method1\n");
//	printOne1(grade+1);
//	printf("\n");
//
//	//
//	printf("method2\n");
//	printOne2(grade,1);
//
//	//
//	printf("method3\n");
//	printOne3(grade,1);


	search1();
	average();
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


//查询同学的成绩是否不及格,打印不及格的同学所有的成绩 
void search1() {
	int i,j;
	int passed = 1;
	for(i=0; i<row; i++) {
		passed = 1;
		for(j=0; j<col; j++) {
			if(*(*(grade+i)+j)<60) {
				passed = 0;
				break;
			}
		}
		if(!passed) {
			printf("student_%d failed:\n",i);
			printOne1(grade+i);
		}
	}
}

//求所有成绩的平均数
void average(){
	float a1=0,a2=0,a3=0,a0=0;
	int i;
	for(i=0;i<row;i++){
		a0+=*(*(grade+i)+0);
		a1+=*(*(grade+i)+1);
		a2+=*(*(grade+i)+2);
		a3+=*(*(grade+i)+3);
	}
	
	printf("average:\n");
	printf("course_0 average: %.2f\n",a0/3);
	printf("course_1 average: %.2f\n",a1/3);
	printf("course_2 average: %.2f\n",a2/3);
	printf("course_3 average: %.2f\n",a3/3);
} 















