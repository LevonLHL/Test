#include <iostream>
using namespace std;
#define Day 7

//����ע��

/*
����ע��
*/

int main1() {
	int a = 10;
	cout << "hello world" << endl;
	cout << "a = " << a << endl;
	cout << "һ��һ���У�" << Day << "��" << endl;
	const int month = 12;
	cout << "һ��һ���У�" << month << "��" << endl;
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

	cout << "short��ռ�ڴ�ռ�: " << sizeof(short) << endl;
	cout << "short��ռ�ڴ�ռ�: " << sizeof(num1) << endl;
	cout << "int��ռ�ռ�: " << sizeof(int) << endl;
	cout << "long��ռ�ռ�: " << sizeof(long) << endl;
	cout << "long long��ռ�ռ�: " << sizeof(long long) << endl;

	//Ĭ��������һ��С����ʾ6λ��Ч����
	float f1 = 3.1415926f;
	double d1 = 3.1415926;
	cout << "f1 = " << f1 << endl;
	cout << "d1 = " << d1 << endl;
	cout << "float��ռ�ռ�: " << sizeof(float) << endl;
	cout << "double��ռ�ռ�: " << sizeof(double) << endl;
	float f2 = 3e2;		//3 * 10 ^ 2
	cout << "f2 = " << f2 << endl;
	float f3 = 3e-2;		//3 * 10 ^ -2
	cout << "f3 = " << f3 << endl;

	char ch = 'a';
	cout << ch << endl;
	cout << "char�ַ��ͱ�����ռ�ڴ棺" << sizeof(char) << endl;
	cout << (int)ch << endl;
	return 0;
}