#include<stdio.h>
#include<string.h>
#include<assert.h>

void reverse(char* str)
{
    assert(str);
    int len = strlen(str);
    char *left = str;
    char *right = str + len - 1;
    
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++,right--;
    }
    
}

int main()
{
    unsigned long pulArrat[] = {6, 7, 8, 9, 10};
    unsigned long *pulPtr;
    pulPtr = pulArrat;
    *(pulPtr + 3) += 3;
    printf("%d,%d\n", *pulPtr, *(pulPtr + 3));
    printf("\n");

    //字符串逆序
    char arr[256] = {0};
    //scanf("%s", arr); //abcdef--->fedvba                scanf不能读取空格
    gets(arr);                                    //读取一行,包括空格
    //逆序函数
    reverse(arr);
    printf("逆序后：%s\n", arr);
    printf("\n");

    //求和
    int a, n = 0;
    scanf("%d%d", &a, &n);//2 5
    int sum = 0;
    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        ret = ret * 10 + a;
        sum += ret;         //a + aa + aaa + ......
    }
    printf("%d\n", sum);
    return 0;
}