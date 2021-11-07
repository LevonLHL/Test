//F9   创建断点和取消断点
//F10  逐过程，通常用来处理一个过程，一个过程可以是一次函数调用，或者是一条语句
//F11  逐语句，就是每次都执行一条语句，但是这个快捷键可以使我们的执行逻辑进入函数内部
//Ctrl+F5  开始执行不调试
//Shift+F11   跳出这个函数
//Shift+F5    停止调试  
#include<stdio.h>

int Add(int x,int y)
{
    int z = 0;
    z = x + y;
    return z;
}

int main()
{
    printf("hehe\n");
    int a = 10;
    int b = 20;
    int ret = 0;
    ret = Add(a, b);            //函数的传参其实就是压栈操作
    return 0;
}