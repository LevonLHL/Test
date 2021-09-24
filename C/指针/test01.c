//指针类型决定了指针进行解引用操作的时候，能够访问空间的大小
//int* p     *p能访问4个字节
//char* p     *p能访问1个字节
//double* p     *p能访问8个字节

//指针类型决定了：指针走一步走多远（指针的步长）
//int* p;p + 1       -->4
//char* p;p + 1      -->1
//double* p;p + 1    -->8
#include<stdio.h>

int main()
{
    printf("%d\n",sizeof(char*));
    printf("%d\n",sizeof(short*));
    printf("%d\n",sizeof(int*));
    printf("%d\n",sizeof(double*));
    printf("------------------------------------------------------------\n");
    int a = 0x11223344;
    int *pa = &a;
    char *pc = &a;
    printf("%p\n", pa);
    printf("%p\n", pc);

    *pa = 0;                //解引用4个字节
    *pc = 0;                //解引用1个字节

    printf("------------------------------------------------------------\n");
    printf("%p\n", pa);
    printf("%p\n", pa + 1);     //地址+4

    printf("%p\n", pc);
    printf("%p\n", pc + 1);     //地址+1
    return 0;
}
