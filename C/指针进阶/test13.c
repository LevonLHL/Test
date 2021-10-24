//指向函数指针数组的指针
#include<stdio.h>


int main()
{
    int arr[10] = {0};
    int(*p)[10] = &arr;      //取出数组的地址

    int (*pf)(int, int);            //函数指针
    int (*pfArr[4])(int, int);      //pfArr是一个数组 - 函数指针的数组
    int (*(*ppfArr[4]))(int, int) = &pfArr;
    //ppfArr 是一个数组指针，指针指向的数组有4个元素
    //指向的数组的每一个元素的类型是一个函数指针 int(*)(int, int)

    return 0;
}