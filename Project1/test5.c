#include <stdio.h>
/*
�ݹ鷨 
*/
void main5() {
	int AppleNum(int day);
	int hano(int num);
	
	printf("%d\n",AppleNum(2));
	printf("%d\n",hano(3));
	
}

/*
һ��ƻ����ÿ���ʣ�µ�һ���һ��
��n�컹��1�������ܹ����ٸ�
*/
int AppleNum(int day) {

	int sum = 0;
	if(day==1) {
		sum = 1;
	} else {
		sum = 2*AppleNum(day-1)+2;
	}
	return sum;
}

/*
��ŵ�� 
*/
int hano(int num){
		int sum = 0;
	if(num==1) {
		sum = 1;
	} else {
		sum = 2*hano(num-1)+1;
	}
	return sum;
}
