//猜数字游戏(电脑随机生成一个数字，猜数字)
#include<stdio.h>
#include<time.h>    //时间戳的库函数（time(NULL)）
#include<stdlib.h>  //rand和srand的库函数

void menu()
{
    printf("*******************\n");
    printf("** 1.play  0.exit**\n");
    printf("*******************\n");
}
void game()
{
    //生成一个随机数，范围[ 0~RAND_MAX（32767）]
    int ret = rand() % 100 + 1;     //生成1~100之间的随机数         
    int guess;      //接收猜的数字
    while (1)
    {
        printf("请猜数字>:");
        scanf("%d", &guess);
        if (guess > ret)
        {
            printf("猜大了！\n");
        }
        else if (guess < ret)
        {
            printf("猜小了！\n");
        }
        else
        {
            printf("恭喜你，猜对了！\n");
            break;
        }
        
    }
    
    printf("正确数字是:%d\n", ret);
}

int main()
{
    int input = 0;
    //时间戳：当前计算机时间-计算机起始时间（1970.1.1.00:00:00）=（xxxx）秒
    //用时间戳来设置随机数的生成起始点
    srand((unsigned int)time(0));    //unsigned是强制类型转换，转换时间戳为整形
    do
    {
        menu();
        printf("请选择(1/0)>:");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();           //游戏
            break;
        case 0:
            printf("退出游戏\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    } while (input);        //为0则跳出循环，非0循环继续
    
    return 0;
}