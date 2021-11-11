#include<stdio.h>

int main()
{
    const int num = 10;

    //const 放在指针变量的*左边时，修饰的是*p，也就是说：不能通过p来改变*p（num）的值
    //const int *p = &num;

    //const 放在指针变量的*右边时，修饰的是指针变量p本身，p不能被改变
    //int *const p = &num;
    
    printf("%d\n", num);
    return 0;
}