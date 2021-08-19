//0~100的整数中出现几个9
#include<stdio.h>

int main()
{
    int i;
    int count = 0;
    for ( i = 0; i <=100; i++)
    {
        if (i % 10 == 9)
        {
            count++;
        }
        if (i / 10 == 9)    //不能用else if,如果前面的if匹配则不进入else if
        {
            count++;
        }
        
        
    }
    printf("count=%d\n", count);
    

    return 0;
}