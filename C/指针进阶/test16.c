#include<stdio.h>
#include<string.h>
//数组名是首元素地址
    //1.sizeof（数组名）  - 数组名表示整个数组
    //2.&数组名         - 数组名表示整个数组


test1()
{
    //一维数组
    int a[] = {1, 2, 3, 4};
    printf("%d\n", sizeof(a));              // 16       数组总大小
    printf("%d\n", sizeof(a + 0));          // 4/8      首元素地址   
    printf("%d\n", sizeof(*a));             // 4        首元素大小
    printf("%d\n", sizeof(a + 1));          // 4/8      第二个元素地址
    printf("%d\n", sizeof(a[1]));           // 4        第二个元素大小
    printf("%d\n", sizeof(&a));             // 4/8      数组的地址
    printf("%d\n", sizeof(*&a));            // 16       *和&能抵消，所以这是数组的大小 
    printf("%d\n", sizeof(&a + 1));         // 4/8      跳过了整个数组的数组地址   
    printf("%d\n", sizeof(&a[0]));          // 4/8      第一个元素的地址
    printf("%d\n", sizeof(&a[0] + 1));      // 4/8      第二个元素的地址
}

test2()
{
    //字符数组
    char arr1[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    printf("%d\n", sizeof(arr1));              // 6        数组总大小
    printf("%d\n", sizeof(arr1 + 0));          // 4/8      首元素地址的大小   
    printf("%d\n", sizeof(*arr1));             // 1        首元素大小
    printf("%d\n", sizeof(arr1[1]));           // 1        第二个元素大小
    printf("%d\n", sizeof(&arr1));             // 4/8      数组的地址
    printf("%d\n", sizeof(&arr1 + 1));         // 4/8      跳过了整个数组的数组地址   
    printf("%d\n", sizeof(&arr1[0] + 1));      // 4/8      第二个元素的地址
    printf("====\n");
    printf("%d\n", strlen(arr1));              // 随机值    找不到\0
    printf("%d\n", strlen(arr1 + 0));          // 随机值    跟上面的写法一样  
    //printf("%d\n", strlen(*arr1));             // err       传的是'a' == 97，非法访问 
    //printf("%d\n", strlen(arr1[1]));           // err       同上，不过是第二个元素
    printf("%d\n", strlen(&arr1));             // 随机值    找不到\0
    printf("%d\n", strlen(&arr1 + 1));         // 随机值    同上，不过比上面的写法小6  
    printf("%d\n", strlen(&arr1[0] + 1));      // 随机值    同上，不过比上面的上面的写法小1
    printf("====\n");

    char arr2[] = "abcdef";
    printf("%d\n", sizeof(arr2));              // 7        数组总大小
    printf("%d\n", sizeof(arr2 + 0));          // 4/8      首元素地址的大小   
    printf("%d\n", sizeof(*arr2));             // 1        首元素大小
    printf("%d\n", sizeof(arr2[1]));           // 1        第二个元素大小
    printf("%d\n", sizeof(&arr2));             // 4/8      数组的地址
    printf("%d\n", sizeof(&arr2 + 1));         // 4/8      跳过了整个数组的数组地址   
    printf("%d\n", sizeof(&arr2[0] + 1));      // 4/8      第二个元素的地址
    printf("====\n");
    printf("%d\n", strlen(arr2));              // 6         首元素地址
    printf("%d\n", strlen(arr2 + 0));          // 6        跟上面的写法一样  
    //printf("%d\n", strlen(*arr2));             // err       传的是'a' == 97，非法访问 
    //printf("%d\n", strlen(arr2[1]));           // err       同上，不过是第二个元素
    printf("%d\n", strlen(&arr2));             // 6       数组地址              数组指针 char (*p)[7] = &arr
    printf("%d\n", strlen(&arr2 + 1));         // 随机值   同上，不过比上面的写法小6，所以是随机值  
    printf("%d\n", strlen(&arr2[0] + 1));      // 5       同上，不过比上面的上面的写法小1
    printf("====\n");

    //p存的是a的地址
    char *p = "abcdef";
    printf("%d\n", sizeof(p));              // 4/8       指针变量p的大小
    printf("%d\n", sizeof(p + 1));          // 4/8       字符b的地址  
    printf("%d\n", sizeof(*p));             // 1        字符串的第一个字符
    printf("%d\n", sizeof(p[0]));           // 1         同上                       arr[0] == *(arr+0)       p[0] == *(p+0)
    printf("%d\n", sizeof(&p));             // 4/8       p的地址
    printf("%d\n", sizeof(&p + 1));         // 4/8      跳过了整个p的地址   
    printf("%d\n", sizeof(&p[0] + 1));      // 4/8      p第二个字符的地址
    printf("====\n");
    printf("%d\n", strlen(p));              // 6         p的地址
    printf("%d\n", strlen(p + 1));          // 5        跟上面的写法一样，不过从b开始找  
    //printf("%d\n", strlen(*p));             // err       传的是'a' == 97，非法访问 
    //printf("%d\n", strlen(p[0]));           // err       同上
    printf("%d\n", strlen(&p));             // 随机值      a地址的地址              
    printf("%d\n", strlen(&p + 1));         // 随机值   同上，不过比上面的写法小6 
    printf("%d\n", strlen(&p[0] + 1));      // 5        从b开始找\0
}

test3()
{
    //二维数组
    int a[3][4] = {0};
    printf("%d\n", sizeof(a));              // 48        数组总大小（3*4*4）
    printf("%d\n", sizeof(a[0][0]));        // 4         第一行的第一个元素
    printf("%d\n", sizeof(a[0]));           // 16        第一行数组的大小
    printf("%d\n", sizeof(a[0] + 1));       // 4/8       第一行第二个元素地址，这里的a[0]指的是第一行数组的首元素地址
    printf("%d\n", sizeof(*(a[0] + 1)));    // 4         第一行第二个元素的大小
    printf("%d\n", sizeof(a + 1));          // 4/8       地址+1还是地址，第二行一维数组的地址（这是把二维数组看成了一维数组）
    printf("%d\n", sizeof(*(a + 1)));       // 16        第二行数组的大小
    printf("%d\n", sizeof(&a[0] + 1));      // 4/8       第二行的地址
    printf("%d\n", sizeof(*(&a[0] + 1)));   // 16        第二行数组的大小
    printf("%d\n", sizeof(*a));             // 16        第一行的大小
    printf("%d\n", sizeof(a[3]));           // 16        不会真的访问到第四行，[3]只是种形式，相当于[0]
}

int main()
{
    test1();
    printf("\n");
    test2();
    printf("\n");
    test3();
    return 0;
}