#include <stdio.h>
/*
ָ��ָ���ַ���
�Լ�ָ������
*/
void main3() {
	void change1(char *s);
	void sort(char *s[],int n);
	void print(char *s[],int n);

	char string1[]= {"I love China!"};
	char *string2 = "I love Japan!";
	char *countries[]= {"France","Australia","Canada","Italy","China","Cuba"};

	change1(string2);

	sort(countries,6);
	print(countries,6);
}

//���ַ�ʽֻ�ܸı�ָ���ָ�򣬼��ٴθ�ֵ�����ܵ����ı�ĳһλ�ַ�
void change1(char *s) {
//	*(s+5) = '#';//��ô�������õģ������б���
	printf("%s\n",s);//������s������*s
	s = "I hate Japan!";
	printf("%s\n",s);


}

//���ַ�����������
void sort(char *s[],int n) {
	char *temp;
	int i,j,k;
	for(i=0; i<n-1; i++) {
		k=i;
		//ѡ������ 
		for(j=i+1; j<n; j++) {
			if(strcmp(s[k],s[j])>0)
				k=j;//ѡ����С�� 
		}
		if(k!=i) {
			temp=s[i];
			s[i]=s[k];
			s[k]=temp;
		}
	}
}

void print(char *s[],int n) {
	int i;
	for(i=0; i<n; i++) {
		printf("%s\n",s[i]);
	}
}




