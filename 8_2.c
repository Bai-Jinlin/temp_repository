#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* fd;
    int c;
    if ((fd = fopen("file1", "r")) == NULL)
        return 1;
    /*while((c=getc(fd))!=EOF) //判断是否到文件尾*/
        /*putchar(c); //输出到stdout*/

    c = getc(fd);
    while (!feof(fd)) { //判断是否到文件
        putchar(c);
        c=getc(fd); //避免出现把EOF写入到文件的现象
    }
    return 0;
}
