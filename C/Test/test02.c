//常量
#include <stdio.h>
#define MAX 10//定义的标识符常量

//枚举关键 - enum
enum Color
{
    red,
    yellow,
    blue,
};
int main()
{
    //const - 常属性,但num是常变量
    const int num = 4;
    printf("%d\n",num);
    //num = 8;  此时再把8赋给num会报错
    printf("===========================================\n");
    int arr[MAX] = {0};
    printf("%d\n", MAX);
    printf("===========================================\n");
    enum Color color = blue;
    printf("%d\n", red);//0
    printf("%d\n", yellow);//1
    printf("%d\n", blue);//2
    return 0;
}