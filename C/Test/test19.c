//找某元素、二分查找法
#include<stdio.h>

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int k = 7;
    int i = 0;
    for ( i = 0; i < sz; i++)
    {
        if (k ==arr[i])
        {
            printf("找到下标是%d的元素\n", i);
            break;
        }
        
    }
    if (i == sz)
        {
            printf("没找到\n");
        }
    printf("===========================================\n");
    //二分查找法(效率高)
    k = 12;
    int left = 0;   //左下标
    int right = sz - 1; //右下标
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] > k)
        {
            right = mid - 1;
        }else if (arr[mid] < k)
        {
            left = mid + 1;
        }else
        {
            printf("下标是%d\n", mid);
            break;
        }
    }
    if (left > right)
    {
        printf("没找到\n");
    }
    
    return 0;
}