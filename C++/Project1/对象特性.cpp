#include<iostream>
using namespace std;

//对象的初始化和清理
class Person
{
public:
	/*1、构造函数（初始化）：									//构造和析构都是必须有的实现，如果我们自己不提供编译器也会提供一个空实现的构造和析构。
			没有返回值且不用写void；							//构造函数调用规则：如果用户定义有参构造函数，C++不再提供默认无参构造函数，但是会提供默认拷贝构造函数（值拷贝）。
			函数名与类名相同；														如果用户定义拷贝构造函数，C++不再提供其他构造函数。
			构造函数可以有参数，可以发生重载；
			创建对象时构造函数会自动调用，而且只调用一次。
	*/
	Person() {												//默认
		cout << "Person()构造函数的调用" << endl;
	}
	Person(int a) {											//有参
		age = a;
		cout << "Person(int a)构造函数的调用" << endl;
	}
	Person(const Person &p) {								//拷贝	1、使用一个对象来初始化一个新对象。2、值传递的方式给函数参数传值。3、值方式返回局部对象。
		//将传入的对象的属性拷贝一份给新对象							
		age = p.age;												
		cout << "Person(const Person &p)构造函数的调用" << endl;
	}
	/*2、析构函数（清除）：						
			没有返回值且不用写void；
			函数名与类名相同且要在前面加~；
			析构函数不可以有参数，不可以发生重载；
			对象销毁时析构函数会自动调用，而且只调用一次。
	*/
	~Person() {
		cout << "~Person()析构函数的调用" << endl;
	}


	int age;
};

void test04() {
	//括号法
	cout << "括号法：" << endl;
	Person p;		//默认		调用默认构造函数时，不要加（），否则编译器会认为是一个函数的声明。
	Person p2(10);	//有参
	Person p3(p2);	//拷贝
	cout << "p2的年龄为：" << p2.age << endl;
	cout << "p3的年龄为：" << p3.age << endl;
	
	//显示法
	cout << "显示法：" << endl;
	Person p4;					//默认
	Person p5 = Person(10);		//有参	
	Person p6 = Person(p5);		//拷贝
	Person(10);		//匿名对象	1、当前行执行结束后，系统会立即回收掉匿名对象。2、不要利用拷贝构造函数初始化匿名对象。
	cout << "匿名对象测试" << endl;

	//隐式转换法
	Person p7 = 10;		//相当于写了 Person p7 = Person(10);
	Person p8 = p7;		//拷贝构造
}


int main14() {
	test04();
	//Person p;
	//system("pause");
	return 0;
}