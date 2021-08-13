//数据类型
#include <stdio.h>

int main(){
    //打印字符类型数据(%c)
    char ch='A';
    printf("%c\n", ch);
    //打印整形数据(%d)
    int age=100;
    printf("%d\n", age);
    //打印浮点型数据(%f)
    float ages=19.56;
    printf("%f\n", ages);
    printf("===============================================\n");
    //各种不同数据类型所占字节数
    printf("%d\n",sizeof(char));
    printf("%d\n",sizeof(short));
    printf("%d\n",sizeof(int));
    printf("%d\n",sizeof(long));
    printf("%d\n",sizeof(long long));
    printf("%d\n",sizeof(float));
    printf("%d\n",sizeof(double));
    printf("===============================================\n");
    //向内存申请2个字节=16bit位，用来存放20
    short num = 20;
    //向内存申请4个字节，存放小数
    float num2 = 95.6f;
    return 0;
}
