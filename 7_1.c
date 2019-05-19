#include <stdio.h>

void foo(int *a,int *b,int *c){
    int temp;
    if(*a<*b) {temp=*b;*b=*a;*a=temp;};
    if(*b<*c) {temp=*c;*c=*b;*b=temp;};
    if(*a<*b) {temp=*b;*b=*a;*a=temp;};
}

int main(int argc, char *argv[])
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    foo(&a,&b,&c);
    printf("%d %d %d\n",a,b,c);
    return 0;
}
