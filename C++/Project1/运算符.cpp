#include <iostream>
using namespace std;

int main3() {
	int a1 = 10, b1 = 3;
	cout << a1 + b1 << endl;
	cout << a1 - b1 << endl;
	cout << a1 * b1 << endl;
	cout << a1 / b1 << endl;			//������Ϊ0
	cout << a1 % b1 << endl;			//������Ϊ0
	double d1 = 0.5;
	float d2 = 0.22f;
	cout << d1 / d2 << endl;			//С��������ȡģ����

	int a = 10;
	cout << ++a << endl;
	cout << a++ << endl;
	cout << a << endl;

	//��ֻС�������
	int d,b,c;
	cout << "������A������:";
	cin >> d;
	cout << "������B������:";
	cin >> b;
	cout << "������C������:";
	cin >> c;
	cout << "���ص���:";
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

	//��Ŀ������Ǳ��������Լ�����ֵ������
	int i = 10, j = 20, k = 0;
	k = (i > j ? i : j);
	cout << "k=" << k << endl;
	(i > j ? i : j) = 100;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	return 0;
}