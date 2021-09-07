#include<stdio.h>

int main()
{
    //优先级
    int a = 10, b = 20;
    int c = b + a * 3;
    printf("%d\n", c); 
    //结合性
    //N/A无结合性
    //L-R从左向右结合
    //R-L从右向左结合
    //是否控制求值顺序

    //问题表达式
    int d, e, f;
    a = a * b + c * d + e * f;      //不能保证三个'*'的运行顺序

    c + --c;                        //虽然知道--在+之前运行,但没办法得知+操作符的左操作数的获取在右操作数之前还是之后求值

    int i = 10;
    i = i-- - --i * (i = -3) * i++ + ++i;           //非法表达式
    printf("i = %d\n", i);

    int answer;
    answer = fun() - fun() * fun();                 //3个fun()中的count值不能确定那个先算
    printf("%d\n", answer);

    i = 1;
    a = (++i) + (++i) + (++i);              //同样无价值
    printf("a = %d\n", a);

    printf("------------------------------------------------------------\n");

    return 0;
}

int fun()
{
    static int count = 1;
    return ++count;
}