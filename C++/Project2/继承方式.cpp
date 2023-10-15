#include<iostream>
using namespace std;



class Base1
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//公共继承（private成员不可访问，其他成员没有变化）
class Son1 :public Base1
{
public:
	void func() {
		m_A = 10;		//父类中的公共权限成员到子类中依然是公共成员
		m_B = 10;		//父类中的保护权限成员到子类中依然是保护成员
		//m_C = 10;		//父类中的私有权限成员子类访问不到
	}

	int m_D;
};
//保护继承（private成员不可访问，其他成员变为protected）
class Son2 :protected Base1
{
public:
	void func() {
		m_A = 10;		//父类中的公共权限成员到子类中变为保护成员
		m_B = 10;		//父类中的保护权限成员到子类中依然是保护成员
		//m_C = 10;		//父类中的私有权限成员子类访问不到
	}
};
//私有继承（private成员不可访问，其他成员变为private）
class Son3 :private Base1
{
public:
	void func() {
		m_A = 10;		//父类中的公共权限成员到子类中变为私有成员
		m_B = 10;		//父类中的保护权限成员到子类中变为私有成员
		//m_C = 10;		//父类中的私有权限成员子类访问不到
	}
};

//Son3的公共继承
class GrandSon3 :public Son3
{
public:
	void func() {			//到了Son3中m_A、m_B、m_C变为私有，及是儿子，也是访问不到
		//m_A = 10;		
		//m_B = 10;		
		//m_C = 10;		
	}
};


class Base
{
public:
	Base() {
		m_A = 100;
	}
	void func() {
		cout << "Base - func()调用" << endl;
	}
	void func(int a) {
		cout << "Base - func(int a)调用" << endl;
	}
	static void func1() {
		cout << "Base - static void func1()调用" << endl;
	}

	int m_A;
	static int m_B;
};
class Son :public Base
{
public:
	Son() {
		m_A = 200;
	}
	void func() {
		cout << "Son - func()调用" << endl;
	}
	static void func1() {
		cout << "Son - static void func1()调用" << endl;
	}

	int m_A;
	static int m_B;
};
int Base::m_B = 100;
int Son::m_B = 200;


//利用虚继承解决菱形继承问题：继承之前加上关键字virtual变为虚继承，变为虚继承后Animal类称为虚基类
class Animal
{
public:
	int m_Age;
};
class Sheep :virtual public Animal
{

};
class Tuo :virtual public Animal
{

};
class SheepTuo :public Sheep, public Tuo
{

};


int main09() {
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;			//到Son1中的m_B是保护权限类外访问不到
	Son2 s2;
	//s2.m_A = 100;			//到Son2中的m_A变为了保护权限类外访问不到
	//s2.m_B = 100;			//到Son2中的m_B是保护权限类外访问不到
	Son3 s3;
	//s3.m_A = 100;			//到Son3中的m_A变为了私有权限类外访问不到
	//s3.m_B = 100;			//到Son3中的m_B变为了私有权限类外访问不到

	cout << "size of Son1 = " << sizeof(Son1) << endl;			//父类中所有非静态成员属性都会被子类继承下去，包括private成员。父类中私有成员属性是被编译器隐藏了，因此是访问不到，但是确实被继承下去了。
																//利用开发人员命令提示工具查看对象模型：先到文件路径下，然后用命令：cl /d1 reportSingleClassLayout类名 "文件名"
	
	Son s;
	cout << "Son下的 m_A = " << s.m_A << endl;
	cout << "Base下的 m_A = " << s.Base::m_A << endl;			//同名成员：如果通过子类对象想要访问到父类中的同名成员需要加作用域
	s.func();													//直接调用优先调用子类的成员函数
	s.Base::func();												//同名函数（也可重载）：当子类与父类拥有同名成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中的同名函数
	s.Base::func(1);
	cout << "通过对象访问静态成员：" << endl;
	cout << "Son下的 m_B = " << s.m_B << endl;					//同名静态成员属性（同上）
	cout << "Base下的 m_B = " << s.Base::m_B << endl;
	s.func1();													//同名静态成员函数（同上），也会隐藏父类中同名成员函数
	s.Base::func1();
	cout << "通过类名访问静态成员：" << endl;
	cout << "Son下的 m_B = " << Son::m_B << endl;
	cout << "Base下的 m_B = " << Son::Base::m_B << endl;		//第一个::代表通过类名方式访问。第二个::代表访问父类作用域下
	Son::func1();
	Son::Base::func1();

	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;	//当菱形继承不用虚继承，两个父类拥有相同数据，需要加以作用域区分，但会有二义性，且有资源浪费
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;					//使用虚继承后可以不加作用域
	return 0;
}

//继承中的构造和析构顺序：先构造父类，再构造子类，析构的顺序与构造的顺序相反。
//利用逗号表达式可以实现多继承（多继承中如果父类中出现了同名情况，子类使用时要加作用域）。语法：class 子类: 继承方式 父类1, 继承方式 父类2 ...
