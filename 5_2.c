#include <stdio.h>

void matrix_transposed(int m[4][4])
{
    int out[4][4]; //转置后的数组
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            out[i][j] = m[j][i]; //转置
    }
    for (int i = 0; i < 4; ++i) { //输出数组
        for (int j = 0; j < 4; ++j)
            printf("%3d ",out[i][j]);
        printf("\n");
    }
}
void matrix_transposed_p(int m[4][4])
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            printf("%3d", m[j][i]); //直接输出转置后的数组
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    int m[4][4];
    for (int i = 0; i < 16; ++i)
        scanf("%d", (int*)m + i);
    matrix_transposed(m);
    return 0;
}
