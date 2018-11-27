#include<stdio.h>
#include<string.h>
void nain(){
char*s:"you are beautiful\0 it is true:
printf("%s\n",s)；
printf("%i\n",sizeof(*s));//1
printf("%d\n",sizeof(s));//8
printf("%d\n",sizeof("you are beautiful\0 it is true"))://30
printf("%d\n",strlen("you are beautiful1e it is true"));//17,会截取。
}
