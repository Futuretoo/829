#include <stdio.h>

/*
����һ��ѧ���ɼ��Ķ�ά���飬��ӡ����Ҫ���ѧ���ĳɼ�
*/
int row=3;//�кţ�������ѧ��
int col=4;//�кţ������ųɼ�
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

//��ӡĳ��ѧ�������гɼ���
//����ĳ�е��׵�ַ����ָ�����
void printOne1(float *a) {
	float *p;
	int i=0;
	//�����ά���飬��aָ��grade[0]��a����ͨfloatָ��
	//p=a,��pָ��grade[0][0]��p����ͨfloatָ��
	for(p=a; i<col; i++) {
		printf("grade%d : %.2f\n",i,*(p+i));
//		printf("grade%d : %.2f\n",i,*(a+i));//p++��a++��ͬ����Ϊ�����ʱ���Ѿ�ת����
	}
}

//��ӡĳ��ѧ�������гɼ�
//��������������к�
void printOne2(float a[][4],int n) {
	int i;
	for(i=0; i<col; i++) {
		printf("grade%d : %.2f\n",i,a[n][i]);
	}
}

//��ӡĳ��ѧ�������гɼ���
//��ָ�봫������������к�
void printOne3(float (*a)[4],int n) {
	//float (*a)[4] ������һ��ָ�룬ָ��һ����4��floatԪ�ص�������׵�ַ
	//��������ά�����ָ�룬��ָ���ά�������е��׵�ַgrade[0]��a��������ָ��
	int i;
	for(i=0; i<col; i++) {
		printf("grade%d : %.2f\n",i,*(*(a+n)+i));
	}
}


//��ѯͬѧ�ĳɼ��Ƿ񲻼���,��ӡ�������ͬѧ���еĳɼ� 
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

//�����гɼ���ƽ����
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















