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

void main() {
	void test41();
	void qus1();
	void qus2();
//	qus1();
	qus2();

}
///////////////////////////////////////
void test41() {
	void printInfo(struct Person s);

	struct Person a = {1,1,"male",18,"Jack",'s',95.5};//98.5Ĭ�ϸ��Ƹ���һ������ֵ
//	a.grade.gradeC = 98.5;

	//union�����ָ��λ�ã�Ĭ���Ǹ�ֵ����һ�����ԣ���grade.gradeC
	struct Person b = {2,1,"female",16,"Sherry",'t',.grade.gradeT='C'};


	printInfo(a);
	printInfo(b);

//	union data d = {98.5,'a'};//��ô��ֵ�Ǵ���ģ���Ϊ����ռ��ͬһ���洢��Ԫ
//ֻ�ܶԵ�һ����ָ����һ�����Ը�ֵ�����������ԻḲ��ǰ���
	union data c = {97.5};
	printf("%.2f\n",c.gradeC);
	printf("%d\n",c.gradeC);//�����ӡ0��˵��float����ֱ�Ӵ�ӡd
	printf("%c\n",(int)c.gradeC);
}

void printInfo(struct Person s) {
	printf("personal info:\n");
	printf("No.:%d\n",s.no);//int�������ֵ��Ĭ��Ϊ0
	printf("name:%s\n",s.name);
	printf("age:%d\n",s.age);
	printf("sex:%s\n",s.sex);
	printf("class:%d\n",s.class);

	//�ַ�������ֱ�ӶԱȣ�ֻ����strcmp����
	//�ַ����ԶԱ�
	if(s.job=='s') {
		printf("grade:%.2f\n",s.grade.gradeC);
	} else
		printf("grade:%c\n",s.grade.gradeT);

	printf("\n");
}
///////////////////////////////////////
//�ṹ�嶨���������Ȼ��ȫ�ֵģ�����ǰ���main�ǵ��ò���
//����main����qus1��qus1���Ե���
struct w {
	char low;
	char high;
};
union u {
	struct w byte;
	short word;
} uw;
///////////////////////////////////////
void qus1() {
	int result;
	uw.word=0x1234;
	printf("word value:%04x\n",uw.word);//1234
	printf("high value:%02x\n",uw.byte.high);//12
	printf("low value:%02x\n",uw.byte.low);//34

	uw.byte.low=0x74;
	printf("word value:%04x\n",uw.word);//1274
	result=uw.word+0x2a34;
	printf("the result:%04x\n",result);//3ca8

	//��Ȼ�����ǳ�ʼ����uw������u��Ȼ���Լ���ʹ��
	union u b;
	b.word=0x2345;
	printf("word value:%04x\n",b.word);//2345

}

struct chars {
	char low;
	char mid;
	char high;
};
union charA {
	struct chars s;
	char chara[3];
};
//����union��ֵ��struct��ʲô˳�� 
void qus2() {
	union charA a= {.chara="abc"};
//	a.chara = {'a','b','c'};//������ֵ�ᱨ��
//	a.chara = "abc";//������ֵҲ�ᱨ��
//��Ϊ����ĸ�ֵ��ֻ��������ʱȫ����ֵ�����ֻ�������ֵ 
	printf("high:%c\n",a.s.high);//c
	printf("mid:%c\n",a.s.mid);//b
	printf("low:%c\n",a.s.low);//a

	a.s.high='a';
	a.s.mid='b';
	a.s.low='c';
	printf("%s",a.chara);//cba@!@

}










