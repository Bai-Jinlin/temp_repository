#include <stdio.h>

void foo(int *a,int n){
    for(int n=n-1;n>=0;--n)
        printf("%d ",*(a+n));
}

void fooo(int *a,int n){
    int *e=a+n-1;
    while(e>=a)
        printf("%d ",*(e--));

}

int main(int argc, char *argv[])
{
    int a[5];
    for(int i=0;i<5;++i)
        scanf("%d",a+i);
    fooo(a,5);
   
    return 0;
}
