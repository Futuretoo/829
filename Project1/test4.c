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
	char job;//
	union data grade;
};
struct Student {
	int no;
	int class;
	char sex[8];
	int age;
	char name[20];//这里要注意，是数组
	char *job;//考试成绩
};
void main() {
	void printInfo(struct Person s);

	struct Person a = {1,1,"male",18,"Jack",'s',95.5};//98.5默认复制给第一个属性值
//	a.grade.gradeC = 98.5;

	//union如果不指定位置，默认是赋值给第一个属性，即grade.gradeC
	struct Person b = {2,1,"female",16,"Sherry",'t',.grade.gradeT='C'};


	printInfo(a);
	printInfo(b);

//	union data d = {98.5,'a'};//这么赋值是错误的，因为他们占用同一个存储单元
//只能对第一个或指定的一个属性赋值，后来的属性会覆盖前面的
	union data c = {97.5};
	printf("%.2f\n",c.gradeC);
	printf("%d\n",c.gradeC);//这里打印0，说明float不能直接打印d 
	printf("%c\n",(int)c.gradeC);

}

void printInfo(struct Person s) {
	printf("personal info:\n");
	printf("No.:%d\n",s.no);//int如果不赋值，默认为0
	printf("name:%s\n",s.name);
	printf("age:%d\n",s.age);
	printf("sex:%s\n",s.sex);
	printf("class:%d\n",s.class);

	//字符串不能直接对比，只能用strcmp函数
	//字符可以对比
	if(s.job=='s') {
		printf("grade:%.2f\n",s.grade.gradeC);
	} else
		printf("grade:%c\n",s.grade.gradeT);

	printf("\n");
}












