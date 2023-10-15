#include<iostream>
using namespace std;


// �Ӻ���������� ������������� ������������� ��ֵ��������� ��ϵ��������� �������������()
class Person
{
		
public:
	//��Ա�������� +��
	/*Person operator+(Person& p) {
		Person temp;
		temp.m_A = this->m_A + p.m_A;
		temp.m_B = this->m_B + p.m_B;
		return temp;
	}*/

	//��Ա�������� <<��
	//�������ó�Ա���������������������Ϊ�޷�ʵ��cout����ࣻ��void operator<<(cout);	p.operator<<(cout)�ļ���p << cout	



	int m_A;
	int m_B;

};


class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger p);		//�������Ԫʹ��
public:
	MyInteger() {
		m_Num = 0;
	}
	//����ǰ��++��������������ã�
	MyInteger& operator++() {								//����������Ϊ��ֻ��һ�����ݽ��в���
		m_Num++;
		return *this;
	}
	//���غ���++�����������ֵ��
	MyInteger operator++(int) {								//int����ռλ������������������ǰ�úͺ��õ���
		//�ȼ�¼��ʱ���
		MyInteger temp = *this;
		//�����
		m_Num++;
		//��󽫼�¼���������
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
	//���ظ�ֵ����� =��
	Person2& operator=(Person2 &p)
	{
		//Ӧ�����ж��Ƿ��������ڶ�������������ͷŸɾ���Ȼ�������
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
	//���ع�ϵ����� ==��
	bool operator==(Person3 &p) {
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age) {
			return true;
		}
		else
		{
			return false;
		}
	}
	//���ع�ϵ����� !=��
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

//��ӡ�����
class MyPrint
{
public:
	//���غ������������ ()��
	void operator()(string test) {				//�����������������ͺ���������
		cout << test << endl;
	}
};




//ȫ�ֺ������� +��
Person operator+(Person& p1,Person& p2) {
	Person temp;
	temp.m_A = p1.m_A + p2.m_A;
	temp.m_B = p1.m_B + p2.m_B;
	return temp;
}
//��������صĺ������ذ汾
Person operator+(Person& p1, int num) {
	Person temp;
	temp.m_A = p1.m_A + num;
	temp.m_B = p1.m_B + num;
	return temp;
}

//ȫ�ֺ������� <<��
ostream& operator<<(ostream &cout,Person &p) {				//����	operator<<(cout,p)����cout<<p��
	cout << "m_A=" << p.m_A << "	m_B=" << p.m_B;
	return cout;											//������ʽ���˼��
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
	Person p3 = p1 + p2;		//��д		��Ա�������ñ�����Person p3 = p1.operator+(p2);ȫ�ֺ������ñ�����Person p3 = operator+(p1,p2)
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
	p7 = p6 = p5;					//��ֵ����
	cout << "p5������Ϊ��" << *p5.m_Age << endl;
	cout << "p6������Ϊ��" << *p6.m_Age << endl;
	cout << "p7������Ϊ��" << *p7.m_Age << endl;

	Person3 p8("Tom", 18);
	Person3 p9("Jerry", 18);
	if (p8 == p9) {
		cout << "p8��p9����ȵģ�==��" << endl;
	}
	else {
		cout << "p8��p9�ǲ���ȵģ�==��" << endl;
	}
	if (p8 != p9) {
		cout << "p8��p9�ǲ���ȵģ�!=��" << endl;
	}
	else {
		cout << "p8��p9����ȵģ�!=��" << endl;
	}

	MyPrint myPrint;
	myPrint("hello world");						//����ʹ�������ǳ������ں������ã���˳�Ϊ�º������º����ǳ����û�й̶���д��
	//������������
	MyPrint()("Levon");							//MyPrint()Ϊ������������+()�������()���Ǻ������������������
	return 0;
}