#include<stdio.h>


//创建一个结构体类型-struct Stu
//学生
struct Stu
{
    char name[20];
    int age;
    char id[20];
};

int main()
{
    int a = 5;
    int b = 10;
    if (a > 4)
    {
        b = 10;
    }
    else
    {
        b = -10;
    }
    b = (a > 4 ? 10 : -10);   //三目操作符
    int max = (a > b ? a : b);
    printf("%d\n", b);
    printf("%d\n", max);
    //逗号表达式：用逗号隔开的多个表达式，从左向右依次执行，整个表达式的结果是最后一个表达式的结果
    a = 1, b = 2;
    int c = (a > b, a = b + 10, a, b = a + 1);
    printf("c = %d\n", c);
    //下标引用操作符
    int d[10] = {0};
    d[4] = 10;
    printf("%d\n", d[4]);
    //使用struct Stu这个类型创建了一个学生对象s1,并初始化
    struct Stu s1 = {"张三", 20, "200010803"};
    //结构体变量.成员名
    printf("%s\n", s1.name);
    printf("%d\n", s1.age);
    printf("%s\n", s1.id);

    struct Stu *ps = &s1;
    printf("%s\n", (*ps).name);
    printf("%d\n", (*ps).age);

    //结构体指针->成员名
    printf("%s\n", ps->name);
    printf("%d\n", ps->age);
    return 0;
}
