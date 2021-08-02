//if语句
#include<stdio.h>

int main()
{
    int age;
    scanf("%d\n", &age);
    if (age < 18)
    {
        printf("未成年\n");
    }else if (age >= 18 && age < 28)
    {
        printf("青年\n");
    }else if (age >= 28 && age < 50)
    {
        printf("壮年\n");
    }else
    {
        printf("老不死\n");
    }
    printf("===========================================\n");
    int a = 0;
    while (a <= 100)
    {
        if (a % 2 != 0)
        {
            printf("%d ", a);
        }
        a++;
    }
    

    return 0;
}