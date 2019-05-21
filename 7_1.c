#include <stdio.h>

void sort(int *a,int *b,int *c){
    int t; //swap中使用的中间变量
    if(*a<*b) t=*b,*b=*a,*a=t; //swap
    if(*b<*c) t=*c,*c=*b,*b=t;
    if(*a<*b) t=*b,*b=*a,*a=t;
}

void sorto(int *a,int *b,int *c){
    if(*a<*b) *a^=*b,*b^=*a,*a^=*b; //利用异或的性质swap
    if(*b<*c) *b^=*c,*c^=*b,*b^=*c;
    if(*a<*b) *a^=*b,*b^=*a,*a^=*b;
}

int main(int argc, char *argv[])
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    sorto(&a,&b,&c);
    printf("%d %d %d\n",a,b,c);
    return 0;
}
