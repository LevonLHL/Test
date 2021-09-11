#include <stdio.h>

int main()
{
    int arr[] = { 0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 0, 6};
    int i = 0;
    //计算数组的元素个数
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < sz; i++)
    {
        int count = 0;//计数器
        int j = 0;
        for (j = 0; j < sz; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
            
        }
        if (count == 1)
        {
            printf("不重复的元素：%d\n", arr[i]);
        }
    }
    printf("===========================================\n");
    int arr1[] = {1, 2, 3, 4, 5, 4, 3, 2, 1,};
    int ret = 0;
    int sz1 = sizeof(arr1) / sizeof(arr1[0]);
    for ( i = 0; i < sz1; i++)
    {
        ret = ret ^ arr1[i];//1^1^2^2^3^3^4^4^5=5
    }
    printf("不重复的元素：%d\n", ret);

    return 0;
}