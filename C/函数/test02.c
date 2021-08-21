#include<stdio.h>

//自定义函数比较两个数的大小
int get_max(int x,int y)
{
    if (x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
    
    
}

//自定义函数交换两个数的大小
void Swap1(int x,int y)      //void表示没有返回值
{
    x = x + y;
    y = x - y;
    x = x - y;
}

void Swap2(int* pa,int* pb)       //pa是指针变量
{
    int tmp = 0;
    tmp = *pa;                    
    *pa = *pb;
    *pb = tmp;    
}


int main()
{
    int a = 10;
    int b = 20;
    //比较大小
    int max = get_max(a, b);
    printf("max=%d\n", max);
    max = get_max(300, 198 + 2);
    printf("max=%d\n", max);
    max = get_max(b, get_max(500, 500 + 1));
    printf("max=%d\n", max);
    printf("=============================================\n");
    //交换失败，因为x、y是局部变量，跟a、b没有关系
    Swap1(a, b);
    printf("a=%d  b=%d\n", a, b);
    //交换成功,直接交换地址
    Swap2(&a, &b);
    printf("a=%d  b=%d\n", a, b);
    return 0;
}

//需要改变函数外部变量时传地址，不改变传值