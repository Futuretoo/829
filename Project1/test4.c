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
///////////////////////////////////////
//结构体定义在这里，虽然是全局的，但是前面的main是调用不到
//但是main调用qus1，qus1可以调用
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

	//虽然定义是初始化了uw，但是u仍然可以继续使用
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
//测试union赋值给struct是什么顺序 
void qus2() {
	union charA a= {.chara="abc"};
//	a.chara = {'a','b','c'};//这样赋值会报错
//	a.chara = "abc";//这样赋值也会报错
//因为数组的赋值，只能在声明时全部赋值；其后只能逐个赋值 
	printf("high:%c\n",a.s.high);//c
	printf("mid:%c\n",a.s.mid);//b
	printf("low:%c\n",a.s.low);//a

	a.s.high='a';
	a.s.mid='b';
	a.s.low='c';
	printf("%s",a.chara);//cba@!@

}










