#include<stdio.h>

int main()
{
    int arr[10] = {0};
    int *p = arr;
    int i = 0;
    for ( i = 0; i < 10; i++)
    {
        printf("%p =====  %p\n", p + i, &arr[i]);
    }
    printf("------------------------------------------------------------\n");
    for ( i = 0; i < 10; i++)
    {
        *(p + i) = i;
        printf("%d ", *(p + i));
    }
    printf("\n");
    for ( i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}