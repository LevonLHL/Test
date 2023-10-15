#include<iostream>
using namespace std;

//浅拷贝：简单的赋值拷贝操作。（带来的问题就是堆区的内存重复释放）		
//深拷贝：在堆区重新申请空间，进行拷贝操作。（解决浅拷贝带来的问题）
class Person
{
public:
	Person() {
		cout << "Person()构造函数的调用" << endl;
	}
	Person(int a, int height) {
		age = a;
		m_height = new int(height);						//如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
		cout << "Person(int a)构造函数的调用" << endl;
	}
	Person(const Person& p) {
		age = p.age;
		//m_height = p.m_height;			浅拷贝编译器默认代码
		//自己实现深拷贝
		m_height = new int(*p.m_height);					//自己在堆区新开一块内存，防止析构函数释放同一堆区的内存
		cout << "Person(const Person &p)构造函数的调用" << endl;
	}

	~Person() {				//析构函数，可以用来释放堆区开辟的内存
		if (m_height != NULL) {
			delete m_height;
			m_height = NULL;
		}
		cout << "~Person()析构函数的调用" << endl;
	}

	int age;
	int* m_height;
};

int main01() {
	Person p1(10, 180);
	Person p2(p1);
	cout << "p1:年龄=" << p1.age << "，身高=" << *p1.m_height << endl;
	cout << "p2:年龄=" << p2.age << "，身高=" << *p2.m_height << endl;
	return 0;
}