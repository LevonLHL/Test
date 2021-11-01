//结构体：结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量  -struct 结构体关键字
#include<stdio.h>

//描述一个学生 — 一些数据
//名字
//年龄
//电话
//性别

//struct-结构体关键字  stu-结构体标签  struct Stu-结构体类型 
struct Stu1
{
    //成员变量(可以是标量、数组、指针，甚至是其他结构体)
    char name[20];
    short age;
    char tele[12];
    char sex[5];
} s1, s2, s3;       //声明类型的同时定义s1,s2,s3是三个全局的结构体变量,分号不能丢
                    

typedef struct Stu
{
    char name[20];
    short age;
    char tele[12];
    char sex[5];
} Stu;          //用typedef把定义的 Stu改名字为 Stu


struct S
{
    int a;
    char c;
    char arr[20];
    double d;
};

struct T
{
    char ch[10];
    struct S s;
    char *pc;
};


int main()
{
    struct Stu1 s4 = {"zhangsan", 20, "78956546", "男"}; //局部变量
    Stu s5 = {"旺财", 30, "78698534", "保密"};

    char arr[] = "hello bit\n";
    struct T t =
        {
            "hehe",
            {100, 'w', "hello word", 3.14},
            arr
        };
    printf("%s\n", t.ch);
    printf("%s\n", t.s.arr);
    printf("%lf\n", t.s.d);
    printf("%s\n", t.pc);
    
    return 0;
}


