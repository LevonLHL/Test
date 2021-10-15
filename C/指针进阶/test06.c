#include<stdio.h>

//一维数组传数组参数时数组大小可以省略，且地址为第一个元素的地址
/*
void test(int arr[])
{}
void test(int arr[10])
{}
void test(int *arr)                    
{}
void test2(int *arr[20])
{}
void test2(int **arr)
{}
*/

void test(int arr[3][5])
{}
void test1(int arr[][5])            //只能省略行，不能省略列
{}
//void test3(int *arr)          //err
//{}
//void test4(int **arr)          //err
//{}
void test5(int (*arr)[5])
{}

int main()
{
    /*
    int arr[10] = {0};
    int *arr2[20] = {0};
    test(arr);
    test2(arr2);
    */
    //二维数组传参
    int arr[3][5] = {0};
    test(arr);
    test1(arr);
    test5(arr);             //arr指向第一行
    return 0;
}