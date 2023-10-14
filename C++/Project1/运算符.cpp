#include <iostream>
using namespace std;

int main3() {
	int a1 = 10, b1 = 3;
	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;			//除数不为0
	cout << a1 % b1 << endl;			//除数不为0
	double d1 = 0.5;
	float d2 = 0.22f;
	cout << d1 / d2 << endl;			//小数不能做取模运算

	int a = 10;
	cout << ++a << endl;
	cout << a++ << endl;
	cout << a << endl;

	//三只小猪称体重
	int d,b,c;
	cout << "请输入A的体重:";
	cin >> d;
	cout << "请输入B的体重:";
	cin >> b;
	cout << "请输入C的体重:";
	cin >> c;
	cout << "最重的是:";
	if (d > b) {
		if (d > c) {
			cout << "A";
		}
		else
		{
			cout << "C";
		}
	}
	else
	{
		if (b > c) {
			cout << "B";
		}
		else
		{
			cout << "C";
		}
	}
	cout << endl;

	//三目运算符是变量，可以继续赋值操作。
	int i = 10, j = 20, k = 0;
	k = (i > j ? i : j);
	cout << "k=" << k << endl;
	(i > j ? i : j) = 100;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	return 0;
}