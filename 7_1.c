#include <stdio.h>

void foo(int *a,int *b,int *c){
    int t;
    if(*a<*b) t=*b,*b=*a,*a=t;
    if(*b<*c) t=*c,*c=*b,*b=t;
    if(*a<*b) t=*b,*b=*a,*a=t;
}

void fooo(int *a,int *b,int *c){
    if(*a<*b) *a^=*b,*b^=*a,*a^=*b;
    if(*b<*c) *b^=*c,*c^=*b,*b^=*c;
    if(*a<*b) *a^=*b,*b^=*a,*a^=*b;
}

int main(int argc, char *argv[])
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    fooo(&a,&b,&c);
    printf("%d %d %d\n",a,b,c);
    return 0;
}
