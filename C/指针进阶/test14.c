//回调函数、排序
#include<stdio.h>
#include<stdalign.h>                    
#include<string.h>

void print(char* str)
{
    printf("hehe:%s\n", str);
}

void test(void (*p)(char*))
{
    printf("test\n");
    p("bit");
}


    //qsort     - 库函数       - 排序
void qsort(void *base,                          //void*   可以接受任意类型的地址，但是不能进行解引用操作，不能进行+-整数的运算
           size_t num,
           size_t width,
           int (*cmp)(const void *e1, const void *e2));
    //第一个参数：待排序数组的首元素地址
    //第二个参数：待排序数组的元素个数
    //第三个参数：待排序数组的每个元素的大小 - 单位字节
    //第四个参数：是函数指针，比较两个元素的所用函数的地址 - 这个得函数使用者自己实现
    //              函数指针的两个参数是：待比较的两个元素的地址

struct Stu
{
    char name[20];
    int age;
};

int cmp_int(const void *e1, const void *e2)
{
    //比较两个整形值的
    return *(int *)e1 - *(int *)e2;
}

void test1()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, sz, sizeof(arr[0]), cmp_int);
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    
}

int cmp_float(const void *e1, const void *e2)
{
    //比较两个浮点数值
    if (*(float *)e1 == *(float *)e2)
        return 0;
    else if (*(float *)e1 > *(float *)e2)
        return 1;
    else
        return -1;

    //return ((int)(*(float *)e1 - *(float *)e2));
}

void test2()
{
    float f[] = {9.5, 8.7, 7.6, 6.2, 5.9, 4.1};
    int sz = sizeof(f) / sizeof(f[0]);
    qsort(f, sz, sizeof(f[0]), cmp_float);
    for (int i = 0; i < sz; i++)
    {
        printf("%f ", f[i]);
    }
    
}

int cmp_stu_by_age(const void *e1, const void *e2)
{
    //比较两个结构体年龄
    return ((struct Stu *)e1)->age - ((struct Stu *)e2)->age;
}

void test3()
{
    struct Stu s[3] = {{"zhangsan", 20}, {"lisi", 30}, {"wangwu", 10}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
    
}

int cmp_stu_by_name(const void *e1, const void *e2)
{
    //比较两个结构体名字
    //比较名字就是比较字符串
    //字符串比较不能直接用'>''<''='来比较，应该用strcmp函数
    return strcmp(((struct Stu *)e1)->name, ((struct Stu *)e2)->name);
}

void test4()
{
    struct Stu s[3] = {{"zhangsan", 20}, {"lisi", 30}, {"wangwu", 10}};
    int sz = sizeof(s) / sizeof(s[0]);
    qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
    
}

int main()
{
    test(print);        //回调函数
    printf("=======================================================\n");
    
    test1();
    printf("\n");
    test2();
    printf("\n");
    test3();
    printf("\n");
    test4();
    return 0;
}