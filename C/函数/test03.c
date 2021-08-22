#include<stdio.h> 
#include<math.h>

//素数
int is_prime(int n)
{
    int m = 0;
    for ( m = 2; m <= sqrt(n); m++)
    {
        if (n % m == 0)
        {
            return 0;
        }
        
    }
    return 1;
}
//闰年
int is_leap_year(int y)
{
    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}
//二分查找
int binary_search(int arr[], int k, int sz)
{
    int left = 0;   //左下标
    int right = sz - 1; //右下标
    while (left <= right)       //'='不能漏
    {
        int mid = (left + right) / 2;    //中间元素的下标
        if (arr[mid] > k)
        {
            right = mid - 1;
        }else if (arr[mid] < k)
        {
            left = mid + 1;
        }else
        {
            return mid;
        }
    }
    return -1;
    
}

int main()
{
    //素数
    int i;
    for ( i = 100; i <= 200; i++)
    {
        //判断i是否为素数
       if (is_prime(i) == 1)
       {
           printf("%d ", i);
       }
       
    }
    printf("\n===========================================\n");
    //闰年
    int year;
    for ( year = 1000; year <= 2000; year++)
    {
        //判断year是否为闰年
        if(is_leap_year(year) == 1)
        {
            printf("%d ", year);
        }
    }
    printf("\n===========================================\n");
    //二分查找
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 7;
    int sz = sizeof(arr) / sizeof(arr[0]);      //不能放在局部区间，放在局部区间是地址
    int ret = binary_search(arr, k, sz);        //函数内部不能求参数部分数组的元素个数
    if (ret == -1)
    {
        printf("找不到指定的数字\n");
    }
    else
    {
        printf("找到了，下标是:%d", ret);
    }
    

    return 0;
}