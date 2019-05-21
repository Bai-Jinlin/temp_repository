#include <stdio.h>

void reverse(int *a,int n){
    for(int i=n-1;i>=0;--i) //使用for结构来输出数组
        printf("%d ",*(a+i));
}

void reversep(int *a,int n){
    int *e=a+n-1;
    while(e>=a) //使用while结构输出数组
        printf("%d ",*(e--));

}

int main(int argc, char *argv[])
{
    int a[5];
    for(int i=0;i<5;++i)
        scanf("%d",a+i);
    reversep(a,5);
    
   
    return 0;
}
