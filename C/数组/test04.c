//冒泡排序
#include<stdio.h>


void bubble_sort(int sz,int arr[])      //int arr[]作为参数用等价于int*arr，都是指针
{
    //确定冒泡排序的趟数
    int i = 0;
    for ( i = 0; i < sz -1 ; i++)
    {
        int flag = 1;       //假设这一趟要排序的数据已经有序
        //每一趟冒泡排序
        int j = 0;
        for ( j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                flag = 0;       //本趟排序的数据其实不完全有序
                int tem = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tem;
            }
            
        }
        if (flag == 1)
        {
            break;
        }
        
    }
    
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    //对arr进行排序，排成升序
    //arr是数组，我们对数组arr进行传参，实际上传递过去的是数组arr首元素的地址 &arr[0]
    bubble_sort(sz,arr);   //冒泡排序
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}