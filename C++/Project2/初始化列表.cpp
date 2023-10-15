#include<iostream>
using namespace std;

class Person
{
public:
	//传统初始化操作
	/*Person(int a, int b, int c) {
		A = a;
		B = b;
		C = c;
	}*/

	//初始化列表初始化属性
	/*Person() :A(100), B(200), C(300) {

	}*/
	Person(int a,int b,int c) :A(a), B(b), C(c) {

	}

	int A;
	int B;
	int C;

};


//类对象作为类成员
class Phone{
public:

	Phone(string pName) {
		m_PName = pName;
		cout << "Phone构造函数调用" << endl;
	}
	~Phone() {
		cout << "~Phone析构函数调用" << endl;
	}

	string m_PName;
};
class Person02 {
public:
	Person02(string name, string pName):m_Name(name),m_Phone(pName) {
		cout << "Person02构造函数调用" << endl;
	}
	~Person02() {
		cout << "Person02析构函数调用" << endl;
	}

	string m_Name;
	Phone m_Phone;			//当其它类对象作为本类成员，构造时先构造类对象，再构造自身，析构的顺序与构造相反
};

void test01() {
	//Person p(10, 20, 30);
	Person p(30,20,10);
	cout << "A=" << p.A << endl;
	cout << "B=" << p.B << endl;
	cout << "C=" << p.C << endl;
}

void test02() {
	Person02 p("张三", "苹果");
	cout << p.m_Name << "用" << p.m_Phone.m_PName << endl;
}

int main02() {
	test01();
	test02();
	return 0;
}