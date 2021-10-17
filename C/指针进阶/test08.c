#include<stdio.h>

int main()
{
    (*(void (*)())0)();     // void (*)()    - 函数指针类型
    //（类型） - 强制类型转换
    //把0强制类型转换成：void(*)() 函数指针类型       - 0就是这个函数的地址
    //调用0地址处的该函数

    void (*signal(int, void (*)(int)))(int);
    //signal是函数声名，参数一个是int，一个是函数指针,该函数指针指向的函数参数是int，返回类型是void
    //signal函数的返回类型也是一个指针：该函数指针指向的函数参数是int，返回类型是void
    //函数指针
    
    //简化
    typedef void (*pfun_t)(int);        //把 void (*)(int) 命名为 pfun_t
    pfun_t signal(int, pfun_t);
    //typedef   - 类型定义
    typedef unsigned int unit;         
    //把 unsigned int 类型命名为 unit
    
    return 0;
}



