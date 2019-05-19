#include <stdio.h>

typedef struct {
    int num;
    float score;
    char name[1024];
} stu;

int main(int argc, char* argv[])
{
    stu sa[]={
        {0,100.0,"foo0"},
        {1,99.9,"foo1"},
        {2,98.8,"foo2"},
        {3,97.7,"foo3"},
        {4,96.6,"foo4"},
    };

    float average=0;
    for(int i=1;i<5;++i)
        average+=sa[i].score;
    printf("average=%f\n",average/5);

    return 0;
}

