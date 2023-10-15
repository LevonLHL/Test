#include<iostream>
using namespace std;


//成员变量和成员函数分开存储

class Person2 {

};

class Person3 {
	int m_A;			//非静态成员变量，属于类对象上
	static int m_B;		//静态成员变量，不属于类对象上
	void func() {		//非静态成员函数，不属于类对象上（静态成员函数同理）

	}
};
int Person3::m_B = 0;

class Person
{
public:

	//静态成员函数：所有的对象共享同一个函数。静态成员函数只能访问静态成员变量
	static void func() {
		m_A = 0;
		//m_C = 200;		静态成员函数只能访问静态成员变量
		cout << "static void func调用" << endl;
	}


	//静态成员变量
	/*1、所有对象都共享同一份数据
	* 2、编译阶段就分配内存
	* 3、类内声明，类外初始化操作
	*/
	static int m_A;

	//静态成员变量和静态成员函数也是有访问权限的
private:
	static void func2() {
		cout << "static void func2调用" << endl;
	}

	static int m_B;
	int m_C;
};
int Person::m_A = 100;
int Person::m_B = 300;

void test03()
{
	Person p;
	cout << p.m_A << endl;
	Person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}

void test04() {
	//静态成员变量不属于某个对象上，所有对象都共享同一份数据
	//因此静态成员变量有两种访问方式
	// 1、通过对象进行访问
	Person p;
	cout << p.m_A << endl;
	// 2、通过类名进行访问
	cout << Person::m_A << endl;
	//cout << Person::m_B << endl;		类外访问不到
}

void test05() {
	//1.通过对象访问
	Person p;
	p.func();
	//2.通过类名访问
	Person::func();
	//Person::func2();					类外访问不到
}

int main03() {
	test03();
	test04();
	test05();

	Person2 p;
	cout << "size of p=" << sizeof(p) << endl;		//空对象占用的内存空间为 1。为了区分对象在内存的位置。
	Person3 p1;
	cout << "size of p1=" << sizeof(p1) << endl;
	return 0;
}