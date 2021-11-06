#include<stdio.h>

typedef struct Stu
{
    char name[20];
    short age;
    char tele[12];
    char sex[5];
} Stu;  




void Print1(Stu s)
{
    printf("name:%s\n", s.name);
    printf("age:%d\n", s.age);
    printf("tele:%s\n", s.tele);
    printf("sex:%s\n", s.sex);
}

void Print2(Stu* ps)
{
    printf("name:%s\n", ps->name);
    printf("age:%d\n", ps->age);
    printf("tele:%s\n", ps->tele);
    printf("sex:%s\n", ps->sex);
}

int main()
{
    Stu s = {"李四", 40, "12378952", "男"};
    Print1(s);
    printf("===============================================\n");
    Print2(&s);         //传地址效果更好,不用开辟其他空间且用时短
    return 0;
}