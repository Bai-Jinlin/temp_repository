#include <stdio.h>

void foo(int *a,int size){
    for(int n=size-1;n>=0;--n)
        printf("%d ",*(a+n));

}

int main(int argc, char *argv[])
{
    int arr[5];
    for(int i=0;i<5;++i)
        scanf("%d",arr+i);
    foo(arr,5);
   
    return 0;
}
