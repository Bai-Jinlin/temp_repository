#include <stdio.h>

void selection_sort(int a[], int size)
{
    int temp,max;
    for (int i = 0; i < size; ++i) {
        max = i;
        for (int j = i + 1; j < size; ++j)
            if (a[j] > a[max]) max = j; //遍历数组找到最大元素的索引
        temp = a[i]; //swap
        a[i] = a[max];
        a[max] = temp;
    }
    for (int i = 0; i < size; ++i) //输出
        printf("%d ", a[i]);
    printf("\n");
}
void selection_sort_p(int a[], int size)
{
    int max;
    for (int i = 0; i < size; ++i) {
        max = i;
        for (int j = i + 1; j < size; ++j)
            if (a[j] > a[max]) max = j; //遍历数组找到最大元素的索引
        printf("%d ",a[max]); //输出最大元素
        a[max]=a[i]; //让max元素等于当前元素
    }
    printf("\n");
}
int main(int argc, char* argv[])
{
    int arr[5];
    for (int i = 0; i < 5; ++i)
        scanf("%d", arr + i);
    selection_sort_p(arr, 5);
    return 0;
}
