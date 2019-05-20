#include <stdio.h>
#include <string.h>
typedef struct {
    int num;
    float score;
    char name[1024];
} stu;

int main(int argc, char* argv[])
{
    // 6_1
    {
        stu s = { 741, 100.0 ,"Lin"};
        printf("name=%s\n"
                "score=%f\n"
                "num=%d\n",
                s.name, s.score, s.num);
    }
    // 6_2
    {
        stu s;
        s.num=557;
        s.score=100.0;
        strcpy(s.name, "lin");
        printf("name=%s\n"
                "score=%f\n"
                "num=%d\n",
                s.name, s.score, s.num);
    }
    return 0;
}
