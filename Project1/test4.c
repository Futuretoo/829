#include <stdio.h>
/*
结构体
共用体
*/
union data {
	float gradeC;//学生的成绩
	char gradeT;//教师的评级
};
struct Person {
	int no;
	int class;
	char sex[8];
	int age;
	char name[20];//这里要注意，是数组
	char job[20];//
	union data grade;
};
struct Student {
	int no;
	int class;
	char sex[8];
	int age;
	char name[20];//这里要注意，是数组
	char job[20];//考试成绩
};
void main() {
	void printInfo(struct Person s);

	struct Person a = {1,1,"male",18,"Jack","stu"};
	a.grade.gradeC = 98.5;
	struct Student b= {.name="Jane",.age=17};


	printInfo(a);
//	printInfo(b);
}

void printInfo(struct Person s) {
	printf("student info:\n");
	printf("No.:%d\n",s.no);//int如果不赋值，默认为0
	printf("name:%s\n",s.name);
	printf("age:%d\n",s.age);
	printf("sex:%s\n",s.sex);
	printf("class:%d\n",s.class);
	if(s.job=="stu") {
		printf("grade:%.2f\n",s.grade.gradeC);
	} else
		printf("grade:%s\n",s.grade.gradeT);
	
	printf("\n");
}












