//goto语句(将代码跳转至),a++、++a,printf打印参数的顺序问题

#include<stdio.h>


int main()
{
    printf("Hello\n");
    goto again;
    printf("你好！");
again:
    printf("hehe");
    printf("\n===========================================\n");
    int a = 10;
    int b = a++ * 2;         //a++先进行其他运算再进行a+1
    printf("%d\n", b);       
    a = 10;
    b = ++a * 2;             //++a先进行a+1再进行其他运算
    printf("%d\n", b);
    printf("\n===========================================\n");
    //printf打印参数的顺序问题
    a = 1, b = 2;
    int c = 3; 
    printf("(a + b + c)的值是%d, b的值是%d, c的值是%d\n", a+b+c, b = b + 1, c = c + 2); //参数从左往右对应，但参数顺序从右往左传
    return 0;
}