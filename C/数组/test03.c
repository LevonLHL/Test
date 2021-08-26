//二维数组
#include<stdio.h>

int main()
{
    //二维数组的列不能省略！！
    int arr[3][4] = {{1, 2, 3},{4, 5}};       //3行4列
    char ch[5][6];
    //打印二维数组
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("===========================================\n");
    //打印二维数组各元素的地址
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
        }

    }
    return 0;
}