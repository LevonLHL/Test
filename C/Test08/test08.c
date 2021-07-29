//static、extern 
#include<stdio.h>

void test1()
{
    int a = 1;
    a++;
    printf("%d\n", a);
}

void test2()
{
    //static使局部变量生命周期变长
    static int a = 1;
    a++;
    printf("%d\n", a);
}

int main()
{
    int i = 0;
    int j = 0;
    while (i<5)
    {
        test1();
        i++;
    }
    printf("===========================================\n");
    while (j<5)
    {
        test2();
        j++;
    }
    //extern --声明外部符号
    printf("===========================================\n");
    extern int g_val;
    printf("g_val=%d\n", g_val);
    return 0;
}
//1.static 修饰局部变量
//局部变量的生命周期变长
//2.static 修饰全局变量
//改变了变量的作用域 --让静态的全局变量只能在自己所在的源文件内部使用
//3.statuc 修饰函数
//也是改变了函数的作用域 --不准确
//static修饰函数改变了函数的链接属性
//外部链接属性 ->内部链接属性