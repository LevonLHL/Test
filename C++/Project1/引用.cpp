#include<iostream>
using namespace std;

//���ô��ݣ��βλ�����ʵ��
void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//�����������ķ���ֵ��1����Ҫ���ؾֲ����������á�2�������ĵ��ÿ�����Ϊ��ֵ
int& test() {
	//int a = 10;
	//return a;
	static int a = 10;
	return a;
}


int main10() {
	//���õĻ����﷨
	//�������� &����=ԭ��
	int a = 10;
	int& b = a;		//�Զ�ת��λint* const b=&a��ָ�볣����ָ��ָ�򲻿��޸ģ�Ҳ˵��Ϊʲô���ò����޸�
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	b = 100;		//�ڲ�����b�����ã��Զ�ת��Ϊ *b=100
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	//1�����ñ���Ҫ��ʼ����2������һ����ʼ���Ͳ����Ը���ָ��
	//int& c;
	/*
	int c = 20;
	int &b = c;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	*/

	a = 10;
	int c = 20;
	mySwap(a, c);
	cout << "a=" << a << endl;
	cout << "c=" << c << endl;

	int& ref = test();
	cout << "ref=" << ref << endl;
	test() = 1000;					//�����ķ���ֵ��һ�������������Ϊ��ֵ
	cout << "ref=" << ref << endl;

	//�������ã�һ�����������βΣ���ֹ�����
	//int& ref2 = 10;					//���ñ�����һ��Ϸ����ڴ�ռ�
	const int& ref2 = 99;			//�������������޸�Ϊint temp=10;const int& ref2 = temp;
	cout << "ref2=" << ref2 << endl;
	//ref2 = 20;		//����const���Ϊֻ��
	return 0;
}