#include <stdio.h>

void selection_sort(int a[], int size)
{
    int temp,max;
    for (int i = 0; i < size; ++i) {
        max = i;
        for (int j = i + 1; j < size; ++j)
            if (a[j] > a[max]) max = j;
        temp = a[i];
        a[i] = a[max];
        a[max] = temp;
    }
    for (int i = 0; i < size; ++i)
        printf("%d ", a[i]);
    printf("\n");
}
int main(int argc, char* argv[])
{
    int arr[5];
    for (int i = 0; i < 5; ++i)
        scanf("%d", arr + i);
    selection_sort(arr, 5);
    return 0;
}
