//数组在内存中是连续存放的
#include<stdio.h>
#include<string.h>

int main()
{
    char arr1[] = "abcdef";
    printf("%c\n", arr1[3]);
    int i = 0;
    int len = strlen(arr1);
    for ( i = 0; i < len; i++)
    {
        printf("%c ", arr1[i]);
    }
    printf("\n===========================================\n");
    int arr2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr2) / sizeof(arr2[0]);
    for ( i = 0; i < sz; i++)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n===========================================\n");
    //数组在内存中是连续存放的
    for ( i = 0; i < sz; i++)
    {
        printf("&arr[%d] = %p\n", i, &arr2[i]);
    }
    
    return 0;
}