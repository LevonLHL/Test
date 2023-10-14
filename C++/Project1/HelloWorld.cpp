#include <iostream>
using namespace std;
#define Day 7

//单行注释

/*
多行注释
*/

int main1() {
	int a = 10;
	cout << "hello world" << endl;
	cout << "a = " << a << endl;
	cout << "一周一共有：" << Day << "天" << endl;
	const int month = 12;
	cout << "一年一共有：" << month << "月" << endl;
	//system("pause");
	int sum1 = 10;
	int sum2 = 20;
	cout << "sum = " << sum1+sum2 << endl;

	short num1 = 32768;
	int num2 = 32768;
	long num3 = 10;
	long long num4 = 10;
	cout << "num1 = " << num1 << endl;
	cout << "num2 = " << num2 << endl;
	cout << "num3 = " << num3 << endl;
	cout << "num4 = " << num4 << endl;

	cout << "short所占内存空间: " << sizeof(short) << endl;
	cout << "short所占内存空间: " << sizeof(num1) << endl;
	cout << "int所占空间: " << sizeof(int) << endl;
	cout << "long所占空间: " << sizeof(long) << endl;
	cout << "long long所占空间: " << sizeof(long long) << endl;

	//默认情况输出一个小数显示6位有效数字
	float f1 = 3.1415926f;
	double d1 = 3.1415926;
	cout << "f1 = " << f1 << endl;
	cout << "d1 = " << d1 << endl;
	cout << "float所占空间: " << sizeof(float) << endl;
	cout << "double所占空间: " << sizeof(double) << endl;
	float f2 = 3e2;		//3 * 10 ^ 2
	cout << "f2 = " << f2 << endl;
	float f3 = 3e-2;		//3 * 10 ^ -2
	cout << "f3 = " << f3 << endl;

	char ch = 'a';
	cout << ch << endl;
	cout << "char字符型变量所占内存：" << sizeof(char) << endl;
	cout << (int)ch << endl;
	return 0;
}