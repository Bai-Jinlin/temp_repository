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

    // 6_2 1
    {
        float average=0;
        for(int i=0;i<5;++i)
            average+=sa[i].score;
        printf("average=%f\n",average/5);

    }
    // 6_2 2
    {
        printf("average=%f\n",
               (sa[0].score+
                sa[1].score+
                sa[2].score+
                sa[3].score+
                sa[4].score)/5);
    }

    return 0;
}

