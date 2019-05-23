#include <stdio.h>

int main(int argc, char *argv[])
{
    FILE *fd;
    if((fd=fopen("file1", "w"))==NULL) //判断函数调用是否成功
        return 1;
    /*fprintf(fd, "AB\nCD");*/
    fputs("AB\nCD\n", fd); //写入
    // w和wb的区别在不同的系统上实现不同
    // 在Windows上文本文件的换行符是\r\n
    // 所以用w打开文件没写入一个\n前面都会补上\r
    // 用wb打开则不会这样
    // 而Unix会忽略w和wb的区别
    return 0;
}
