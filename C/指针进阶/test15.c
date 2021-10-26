//用回调函数模拟冒泡排序排序多种数据类型
#include<stdio.h>


struct Stu
{
    char name[20];
    int age;
};

void bubble_sort(void* base, int sz, int width, int (*cmp)(void* e1, void* e2))     //为了实现比较多种数据类型，把各种数据类型都封装成一个函数，传到
{                                                                                   //      bubble_sort里，用函数指针接收，参数用void*接收是为了接受任意类型
    //趟数
    for (int i = 0; i < sz - 1; i++)
    {
        //每一趟比较的对数
        for (int j = 0; j < sz - 1 -j; j++)
        {
            //两个元素的比较
            if (cmp((char *)base + j * width, (char *)base + (j + 1) * width) > 0)
            {
                //交换
                Swap((char *)base + j * width, (char *)base + (j + 1) * width, width);
            }
        }
        
    }
    
}

void Swap(char* buf1, char* buf2, int width)
{
    int i = 0;
    for ( i = 0; i < width; i++)
    {
        char tmp = *buf1;
        *buf1 = *buf2;
        *buf2 = tmp;
        buf1++;
        buf2++;
    }
    
}

int cmp_int(const void *e1, const void *e2)
{
    //比较两个整形值的
    return *(int *)e1 - *(int *)e2;
}

int cmp_stu_by_name(const void *e1, const void *e2)
{
    //比较两个结构体名字
    //比较名字就是比较字符串
    //字符串比较不能直接用'>''<''='来比较，应该用strcmp函数
    return strcmp(((struct Stu *)e1)->name, ((struct Stu *)e2)->name);
}

void test()
{
    int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sz = sizeof(arr) / sizeof(arr[0]);
    bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
}

void test1()
{
    struct Stu s[3] = {{"zhangsan", 20}, {"lisi", 30}, {"wangwu", 10}};
    int sz = sizeof(s) / sizeof(s[0]);
    bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_name);
}


int main()
{
    test();
    test1();
    
    return 0;
}
