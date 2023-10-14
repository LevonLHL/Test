#include<iostream>
using namespace std;

//引用传递，形参会修饰实参
void mySwap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//引用做函数的返回值：1、不要返回局部变量的引用。2、函数的调用可以作为左值
int& test() {
	//int a = 10;
	//return a;
	static int a = 10;
	return a;
}


int main10() {
	//引用的基本语法
	//数据类型 &别名=原名
	int a = 10;
	int& b = a;		//自动转换位int* const b=&a，指针常量是指针指向不可修改，也说明为什么引用不可修改
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	b = 100;		//内部发现b是引用，自动转换为 *b=100
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;

	//1、引用必须要初始化。2、引用一旦初始化就不可以更改指向。
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
	test() = 1000;					//函数的返回值是一个引用则可以作为左值
	cout << "ref=" << ref << endl;

	//常量引用，一般用来修饰形参，防止误操作
	//int& ref2 = 10;					//引用必须引一块合法的内存空间
	const int& ref2 = 99;			//编译器将代码修改为int temp=10;const int& ref2 = temp;
	cout << "ref2=" << ref2 << endl;
	//ref2 = 20;		//加入const后变为只读
	return 0;
}