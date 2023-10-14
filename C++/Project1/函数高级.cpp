#include<iostream>
using namespace std;

//函数的默认参数,有传入用传入，没传入用默认
int func(int a,int b=20,int c=30) {			//如果某个位置已经有了默认参数，那么从这个位置往后都应该有默认参数
	return a + b + c;
}
//如果函数声明有默认参数，那函数的实现就不能有默认参数
int func2(int a=10, int b=10);
int func2(int a, int b) {		
	return a + b;
}


//函数的占位参数,占位参数还可以有默认参数如:void test(int = 10)
void test(int a,int) {
	cout << "This is test" << endl;
}


//函数重载：1、同一个作用域下。2、函数名称相同。3、函数参数类型不同或者个数不同或者顺序不同。
void test01() {
	cout << "This is test01" << endl;
}
/*   函数的返回值不可以作为函数重载的条件
int test01() {
	cout << "This is test01" << endl;
}
*/
void test01(int a) {
	cout << "This is test01(int a)" << endl;
}
void test01(double a) {
	cout << "This is test01(double a)" << endl;
}
void test01(int a,double b) {
	cout << "This is test01(int a,double b)" << endl;
}
void test01(double a,int b) {
	cout << "This is test01(double a,int b)" << endl;
}

//引用作为重载的条件
void test02(int &a) {
	cout << "This is test02(int &a)" << endl;
}
void test02(const int& a) {
	cout << "This is test02(const int &a)" << endl;
}
//函数重载碰到默认参数
void test03(int a,int b=10) {
	cout << "This is test03(int a,int b=10)" << endl;
}
void test03(int a) {
	cout << "This is test03(int a)" << endl;
}

int main11() {
	cout << func(10) << endl;
	cout << func(10,30) << endl;
	cout << func2(30) << endl;

	test(1,10);

	test01();
	test01(1);
	test01(3.14);
	test01(2, 3.14);
	test01(10.0, 10);

	int a = 10;
	test02(a);
	test02(10);

	//test03(20);	//出现二义性报错
	test03(10, 20);
	return 0;
}