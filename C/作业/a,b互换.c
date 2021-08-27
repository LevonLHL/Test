#include <stdio.h>

int main()
{
    int a = 3;
    int b = 5;
    printf("更改前：a=%d  b=%d\n", a, b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("更改后：a=%d  b=%d\n", a, b);
    printf("===========================================\n");
    int x = 7;
    int y = 8;
    printf("更改前：x=%d  y=%d\n", x, y);
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
    printf("更改后：x=%d  y=%d\n", x, y);
    return 0;
}