#include<string.h>
#include<stdio.h>
//结构体
struct Book
{
    char name[20];//C语言
    short price;//55
};
int main()
{
    struct Book b1 = {"C语言", 55};
    printf("书名：%s\n", b1.name);
    printf("价额：%d\n", b1.price);
    b1.price = 15;//更改的变量
    printf("价额：%d\n", b1.price);
    printf("===========================================\n");
    //利用pd打印出书名和价格
    struct Book *pb = &b1;
    //结构体变量.成员
    printf("书名：%s\n", (*pb).name);
    printf("价格：%d\n", (*pb).price);
    printf("或\n");
    //结构体指针->成员
    printf("书名：%s\n", pb->name);
    printf("价格：%d\n", pb->price);
    printf("===========================================\n");
    strcpy(b1.name, "C++");//更改字符串(string.h)
    printf("书名：%s\n", b1.name);
    return 0;
}