#include <stdio.h>
/*
�ṹ��
������
*/
union data {
	float gradeC;//ѧ���ĳɼ�
	char gradeT;//��ʦ������
};
struct Person {
	int no;
	int class;
	char sex[8];
	int age;
	char name[20];//����Ҫע�⣬������
	char job[20];//
	union data grade;
};
struct Student {
	int no;
	int class;
	char sex[8];
	int age;
	char name[20];//����Ҫע�⣬������
	char job[20];//���Գɼ�
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
	printf("No.:%d\n",s.no);//int�������ֵ��Ĭ��Ϊ0
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












