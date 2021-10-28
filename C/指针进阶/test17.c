#include<stdio.h>

struct Test
{
    //已知结构体Test类型的变量大小是20个字节
    int Num;
    char *pcName;
    short sDate;
    char cha[2];
    short sBa[4];
} * p;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int *ptr = (int *)(&a + 1);                 //(&a + 1)实际上加了20
    printf("%d,%d\n", *(a + 1), *(ptr - 1));        //2,5     *（prt - 1）实际上减了4，解引用后也就是a数组的最后一个元素
    printf("\n");                                   //           而*（a + 1）是把地址移到了第二个元素上

    // 0x1   - 16进制的1
    //假设p的值为0x100000
    p = (struct Test *)0x100000;
    printf("%p\n", p + 0x1);                    //00100020 == 0x00100014
    printf("%p\n", (unsigned long)p + 0x1);     //0x00100001
    printf("%p\n", (unsigned int *)p + 0x1);        //0x00100004
    printf("\n");

    //%x  - 表示以16进制整数形式输出
    int a1[4] = {1, 2, 3, 4};
    int *ptr1 = (int *)(&a1 + 1);           //+16
    int *ptr2 = (int *)((int)a1 + 1);       //由于a1被强制类型转换成整形，所以+1只在内存中移动一个字节
    printf("%x,%x\n", ptr1[-1], *ptr2);     // 0x4,0x02000000（小端模式）
    printf("\n");

    int a2[3][2] = {(0, 1), (2, 3), (4, 5)};        //(0,1)其实是逗号表达式
    int *p2;
    p2 = a2[0];
    printf("%d\n", p2[0]);              //输出1
    printf("\n");

    int a3[5][5];
    int(*p3)[4];
    p3 = a3;
    //p[4][2] == *(*(p+2)+2)
    printf("%p,%d\n", &p3[4][2] - &a3[4][2], &p3[4][2] - &a3[4][2]);        //100000000000000000000000000000100     -4
    printf("\n");                                                           //111111111111111111111111111111011
                                                                            //111111111111111111111111111111100     地址不存在有无符号，直接拿补码

    int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *ptr3 = (int *)(&aa + 1);           //跳过整个二维数组
    int *ptr4 = (int *)(*(aa + 1));         //跳过第一个一维数组
    printf("%d,%d", *(ptr3 - 1), *(ptr4 - 1));      //10,5
    printf("\n");

    char *a4[] = {"work", "at", "alibaba"};
    char **pa4 = a4;                    //实际上*pa才是储存的字符串
    pa4++;                              //首元素地址+1(把一个字符串看成一个元素)
    printf("%s\n", *pa4);               // 'at'
    printf("\n");

    char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
    char **cp[] = {c + 3, c + 2, c + 1, c};     //c + 3 == FIRST, c + 2 == POINT, c + 1 == NEW, c == ENTER
    char ***cpp = cp;                           // cp == c + 3 == FIRST
    printf("%s\n", **++cpp);                    //POINT
    printf("%s\n", *--*++cpp + 3);              //ER
    printf("%s\n", *cpp[-2] + 3);               //ST
    printf("%s\n", cpp[-1][-1] + 1);           //EW             *(*(cpp-1)-1)+1
    return 0;
}