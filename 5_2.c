#include <stdio.h>

void matrix_reverse(int m[4][4])
{
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            printf("%3d", m[3 - j][3 - i]);
        printf("\n");
    }
}

int main(int argc, char* argv[])
{
    int m[4][4];
    for (int i = 0; i < 16; ++i)
        scanf("%d", (int*)m + i);

    matrix_reverse(m);
    return 0;
}
