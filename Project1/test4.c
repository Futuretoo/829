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
	char job;//
	union data grade;
};
struct Student {
	int no;
	int class;
	char sex[8];
	int age;
	char name[20];//����Ҫע�⣬������
	char *job;//���Գɼ�
};
void main() {
	void printInfo(struct Person s);

	struct Person a = {1,1,"male",18,"Jack",'s',95.5};
//	a.grade.gradeC = 98.5;

	//union�����ָ��λ�ã�Ĭ���Ǹ�ֵ����һ�����ԣ���grade.gradeC 
	struct Person b = {2,1,"female",16,"Sherry",'t',.grade.gradeT='C'};


	printInfo(a);
	printInfo(b);
}

void printInfo(struct Person s) {
	printf("personal info:\n");
	printf("No.:%d\n",s.no);//int�������ֵ��Ĭ��Ϊ0
	printf("name:%s\n",s.name);
	printf("age:%d\n",s.age);
	printf("sex:%s\n",s.sex);
	printf("class:%d\n",s.class);
	//�ַ�������ֱ�ӶԱȣ�ֻ����strcmp���� 
	if(s.job=='s') {
		printf("grade:%.2f\n",s.grade.gradeC);
	} else
		printf("grade:%c\n",s.grade.gradeT);
	
	printf("\n");
}












