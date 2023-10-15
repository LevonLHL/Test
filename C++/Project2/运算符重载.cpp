#include<iostream>
using namespace std;


// 加号运算符重载 左移运算符重载 递增运算符重载 赋值运算符重载 关系运算符重载 函数调用运算符()
class Person
{
		
public:
	//成员函数重载 +号
	/*Person operator+(Person& p) {
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}*/

	//成员函数重载 <<号
	//不会利用成员函数重载左移运算符，因为无法实现cout在左侧；例void operator<<(cout);	p.operator<<(cout)的简化是p << cout	



	int m_A;
	int m_B;

};


class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger p);		//可配合友元使用
public:
	MyInteger() {
		m_Num = 0;
	}
	//重载前置++运算符（返回引用）
	MyInteger& operator++() {								//返回引用是为了只对一份数据进行操作
		m_Num++;
		return *this;
	}
	//重载后置++运算符（返回值）
	MyInteger operator++(int) {								//int代表占位参数，可以用于区分前置和后置递增
		//先记录当时结果
		MyInteger temp = *this;
		//后递增
		m_Num++;
		//最后将记录结果做返回
		return temp;
	}

private:
	int m_Num;
};


class Person2
{
public:
	Person2(int age) {
		m_Age = new int(age);
	}
	~Person2() {
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
	}
	//重载赋值运算符 =号
	Person2& operator=(Person2 &p)
	{
		//应该先判断是否有属性在堆区，如果有先释放干净，然后再深拷贝
		if (m_Age != NULL) {
			delete m_Age;
			m_Age = NULL;
		}
		m_Age = new int(*p.m_Age);
		return *this;
	}


	int* m_Age;
};


class Person3
{
public:
	Person3(string name,int age) {
		m_Name = name;
		m_Age = age;
	}
	//重载关系运算符 ==号
	bool operator==(Person3 &p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		else
		{
			return false;
		}
	}
	//重载关系运算符 !=号
	bool operator!=(Person3& p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return false;
		}
		else
		{
			return true;
		}
	}


	string m_Name;
	int m_Age;
};

//打印输出类
class MyPrint
{
public:
	//重载函数调用运算符 ()号
	void operator()(string test) {				//可以有其他返回类型和其他参数
		cout << test << endl;
	}
};




//全局函数重载 +号
Person operator+(Person& p1,Person& p2) {
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//运算符重载的函数重载版本
Person operator+(Person& p1, int num) {
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

//全局函数重载 <<号
ostream& operator<<(ostream &cout,Person &p) {				//本质	operator<<(cout,p)，简化cout<<p。
	cout << "m_A=" << p.m_A << "	m_B=" << p.m_B;
	return cout;											//符合链式编程思想
}
ostream& operator<<(ostream& cout, MyInteger p) {
	cout << "m_Num=" << p.m_Num;
	return cout;
}

int main07() {
	Person p1;
	p1.m_A = 10;
	p1.m_B = 10;
	Person p2;
	p2.m_A = 10;
	p2.m_B = 10;
	Person p3 = p1 + p2;		//简写		成员函数调用本质是Person p3 = p1.operator+(p2);全局函数调用本质是Person p3 = operator+(p1,p2)
	cout << "p3.m_A=" << p3.m_A << endl;
	cout << "p3.m_B=" << p3.m_B << endl;

	Person p4 = p1 + 100;
	cout << "p4.m_A=" << p4.m_A << endl;

	cout << p1 << endl;

	MyInteger myint;
	cout << ++myint << endl;
	cout << myint++ << endl;
	cout << myint << endl;

	Person2 p5(18);
	Person2 p6(20);
	Person2 p7(30);
	p7 = p6 = p5;					//赋值操作
	cout << "p5的年龄为：" << *p5.m_Age << endl;
	cout << "p6的年龄为：" << *p6.m_Age << endl;
	cout << "p7的年龄为：" << *p7.m_Age << endl;

	Person3 p8("Tom", 18);
	Person3 p9("Jerry", 18);
	if (p8 == p9) {
		cout << "p8和p9是相等的（==）" << endl;
	}
	else {
		cout << "p8和p9是不相等的（==）" << endl;
	}
	if (p8 != p9) {
		cout << "p8和p9是不相等的（!=）" << endl;
	}
	else {
		cout << "p8和p9是相等的（!=）" << endl;
	}

	MyPrint myPrint;
	myPrint("hello world");						//由于使用起来非常类似于函数调用，因此称为仿函数，仿函数非常灵活没有固定的写法
	//匿名函数对象
	MyPrint()("Levon");							//MyPrint()为匿名对象，类名+()，后面的()又是函数调用运算符的重载
	return 0;
}