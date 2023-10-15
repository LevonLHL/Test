#include<iostream>
using namespace std;

class Person
{
public:
	//��ͳ��ʼ������
	/*Person(int a, int b, int c) {
		A = a;
		B = b;
		C = c;
	}*/

	//��ʼ���б��ʼ������
	/*Person() :A(100), B(200), C(300) {

	}*/
	Person(int a,int b,int c) :A(a), B(b), C(c) {

	}

	int A;
	int B;
	int C;

};


//�������Ϊ���Ա
class Phone{
public:

	Phone(string pName) {
		m_PName = pName;
		cout << "Phone���캯������" << endl;
	}
	~Phone() {
		cout << "~Phone������������" << endl;
	}

	string m_PName;
};
class Person02 {
public:
	Person02(string name, string pName):m_Name(name),m_Phone(pName) {
		cout << "Person02���캯������" << endl;
	}
	~Person02() {
		cout << "Person02������������" << endl;
	}

	string m_Name;
	Phone m_Phone;			//�������������Ϊ�����Ա������ʱ�ȹ���������ٹ�������������˳���빹���෴
};

void test01() {
	//Person p(10, 20, 30);
	Person p(30,20,10);
	cout << "A=" << p.A << endl;
	cout << "B=" << p.B << endl;
	cout << "C=" << p.C << endl;
}

void test02() {
	Person02 p("����", "ƻ��");
	cout << p.m_Name << "��" << p.m_Phone.m_PName << endl;
}

int main02() {
	test01();
	test02();
	return 0;
}