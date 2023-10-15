#include<iostream>
using namespace std;

//��ͨд��
class Calculator
{
public:
	int getResult(string oper) {
		if (oper == "+")	return m_Num1 + m_Num2;
		else if (oper == "-")return m_Num1 - m_Num2;
		else if (oper == "*")return m_Num1 * m_Num2;
		/*
		�������չ�µĹ��ܣ���Ҫ�޸�Դ��
		����ʵ�ʿ������ᳫ ����ԭ�򣺶���չ���п��ţ����޸Ľ��йرա�
		*/
	}


	int m_Num1;			//������1
	int m_Num2;			//������2
};


//��̬д��						�ô���1����֯�ṹ������2���ɶ���ǿ��3������ǰ�ںͺ��ڵ���չ�Լ�ά���Ըߡ�
//ʵ�ּ�����������
class AbstractCalculator				//ֻҪ��һ�����麯����������Ϊ�����ࡣ�ص㣺1���޷�ʵ��������2����������������Ҫ��д�����еĴ��麯��������Ҳ���ڳ����ࡣ
{
public:
	//���麯������( )��ȫ���� = 0��ǰ���Ǳ���Ϊ�麯����
	virtual int getResult() = 0;				

	int m_Num1;			//������1
	int m_Num2;			//������2
};
//�ӷ���������
class AddCalculator :public AbstractCalculator
{
public:
	virtual int getResult() {

		return m_Num1 + m_Num2;
	}

};
//������������
class SubCalculator :public AbstractCalculator
{
public:
	virtual int getResult() {

		return m_Num1 - m_Num2;
	}

};
//�˷���������
class MulCalculator :public AbstractCalculator
{
public:
	virtual int getResult() {

		return m_Num1 * m_Num2;
	}

};

//����̳г�����
class test :public AbstractCalculator
{
public:

};

int main11() {
	cout << "��ͨʵ�֣�" << endl;
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;
	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;


	cout << "��̬ʵ�֣�" << endl;													
	//����ָ�������ָ���������
	//�ӷ�����
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	//��������
	abc = new SubCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;
	//�˷�����
	abc = new MulCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 100;
	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
	delete abc;

	//AbstractCalculator b;													//�������޷�ʵ��������
	//new AbstractCalculator;
	//test t;																//���������д�����еĴ��麯���������޷�ʵ��������
	return 0;
}