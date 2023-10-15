#include<iostream>
using namespace std;

//普通写法
class Calculator
{
public:
	int getResult(string oper) {
		if (oper == "+")	return m_Num1 + m_Num2;
		else if (oper == "-")return m_Num1 - m_Num2;
		else if (oper == "*")return m_Num1 * m_Num2;
		/*
		如果想扩展新的功能，需要修改源码
		但在实际开发中提倡 开闭原则：对扩展进行开放，对修改进行关闭。
		*/
	}


	int m_Num1;			//操作数1
	int m_Num2;			//操作数2
};


//多态写法						好处：1、组织结构清晰。2、可读性强。3、对于前期和后期的扩展以及维护性高。
//实现计算器抽象类
class AbstractCalculator				//只要有一个纯虚函数，这个类称为抽象类。特点：1、无法实例化对象。2、抽象类的子类必须要重写父类中的纯虚函数，否则也属于抽象类。
{
public:
	//纯虚函数：把( )后全换成 = 0，前提是必须为虚函数。
	virtual int getResult() = 0;				

	int m_Num1;			//操作数1
	int m_Num2;			//操作数2
};
//加法计算器类
class AddCalculator :public AbstractCalculator
{
public:
	virtual int getResult() {

		return m_Num1 + m_Num2;
	}

};
//减法计算器类
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult() {

		return m_Num1 - m_Num2;
	}

};
//乘法计算器类
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult() {

		return m_Num1 * m_Num2;
	}

};

//子类继承抽象类
class test :public AbstractCalculator
{
public:

};

int main11() {
	cout << "普通实现：" << endl;
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;


	cout << "多态实现：" << endl;													
	//父类指针或引用指向子类对象
	//加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	//减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	//乘法运算
	abc = new MulCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;

	//AbstractCalculator b;													//抽象类无法实例化对象
	//new AbstractCalculator;
	//test t;																//子类必须重写父类中的纯虚函数，否则无法实例化对象
	return 0;
}