#include <stdio.h>
#include <stdlib.h>

/*
用指针交换一个数组的顺序 
 */
int main1() {
	void rev1(int *p,int n);
	void rev2(int *p,int n);
	void printArray(int *p,int n);

	int nums[]= {1,2,3,4,5,6,7,8,9,10};
	rev2(nums,10);

	printArray(nums,10);
}

//使用计数器i
void rev1(int *p,int n) {
	int i,temp;
	for(i=0; i<(n/2+1); i++) {
		temp=*(p+i);
		*(p+i)=*(p+n-i-1);
		*(p+n-i-1)=temp;
	}
}

//使用两个指针遍历
void rev2(int *p,int n) {
	int temp,*p1,*p2;
	p1=p;
	p2=p+n-1;
	for(; p1<p2; p1++,p2--) {
		temp=*p1;
		*p1=*p2;
		*p2=temp;
	}
}
//打印数组 
void printArray(int *p,int n) {
	int i=0;
	for(; i<n; i++) {
		printf("%d\n",*(p++));
	}
}
