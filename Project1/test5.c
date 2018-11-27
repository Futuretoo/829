#include <stdio.h>
/*
递归法 
*/
void main5() {
	int AppleNum(int day);
	int hano(int num);
	
	printf("%d\n",AppleNum(2));
	printf("%d\n",hano(3));
	
}

/*
一堆苹果，每天吃剩下的一半加一个
第n天还有1个，求总共多少个
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
汉诺塔 
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
