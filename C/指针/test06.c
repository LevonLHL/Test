//二级指针
#include<stdio.h>

int main()
{
    int a = 10;
    int *pa = &a;
    int **ppa = &pa;        //ppa就是二级指针
    int ***pppa = &ppa;    //pppa三级指针
    printf("%p\n", &pa);
    printf("%p\n", &ppa);
    printf("%d\n", ***pppa);
    //指针数组 --数组       -存放指针的数组
    int d = 10, b = 20, c = 30;
    int *arr2[3] = {&d, &b, &c};
    for (int i = 0; i < 3; i++)
    {
        printf("%d ",*(arr2[i]));
    }
    
    //数组指针 --指针
    return 0;
}