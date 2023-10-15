#include<iostream>
using namespace std;


//this指针：1、解决名称冲突。2、返回对象本身用 *this。
class Person
{
public:
	Person(int age) {
		//this指针指向被调用的成员函数所属的对象
		this->age = age;
	}
	Person& PersonAddAge(Person p) {
		this->age += p.age;
		return *this;		//返回对象本身，可用来做链式编程思想的操作
	}


	//空指针调用成员函数
	void showClassName() {
		cout << "this is person class" << endl;
	}
	void showPersonAge() {
		if (this == NULL)	return;					//可提前进行空指针的判断
		cout << "age=" << m_Age << endl;			//这里m_Age前面是默认有this->的，函数报错的原因是传入的指针为NULL
	}


	//常函数
	void showPerson() const							//成员函数名后加const，修饰的是this指针相当于const Person * const this，即指向的值也不可修改了
	{
		//m_Age = 100;								//同样隐含了this指针。this指针的本质是指针常量（Person * const this），指针的指向是不可修改的
		m_B = 100;
	}


	int age;
	int m_Age;
	mutable int m_B;				//特殊变量，即使在常函数中，也可以修改这个值，加上关键字mutable
};

int main05() {
	Person p1(10);
	cout << "p1的年龄：" << p1.age << endl;

	Person p2(18);
	cout << "p2的年龄：" << p2.age << endl;
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);			//链式编程思想
	cout << "p2的年龄：" << p2.age << endl;

	Person* p3 = NULL;
	p3->showClassName();
	p3->showPersonAge();

	p1.showPerson();
	cout << "p1的m_B：" << p1.m_B << endl;
	//常对象
	const Person p4(100);							//对象前加const，变为常对象
	//p4.m_Age = 100;								//常对象的值不可更改
	p4.m_B = 100;									//m_B具有mutable关键字可以修改
	//常对象只能调用常函数
	p4.showPerson();
	//p4.showPersonAge();
	return 0;
}