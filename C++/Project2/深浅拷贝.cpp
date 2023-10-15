#include<iostream>
using namespace std;

//ǳ�������򵥵ĸ�ֵ������������������������Ƕ������ڴ��ظ��ͷţ�		
//������ڶ�����������ռ䣬���п��������������ǳ�������������⣩
class Person
{
public:
	Person() {
		cout << "Person()���캯���ĵ���" << endl;
	}
	Person(int a, int height) {
		age = a;
		m_height = new int(height);						//����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������
		cout << "Person(int a)���캯���ĵ���" << endl;
	}
	Person(const Person& p) {
		age = p.age;
		//m_height = p.m_height;			ǳ����������Ĭ�ϴ���
		//�Լ�ʵ�����
		m_height = new int(*p.m_height);					//�Լ��ڶ����¿�һ���ڴ棬��ֹ���������ͷ�ͬһ�������ڴ�
		cout << "Person(const Person &p)���캯���ĵ���" << endl;
	}

	~Person() {				//�������������������ͷŶ������ٵ��ڴ�
		if (m_height != NULL) {
			delete m_height;
			m_height = NULL;
		}
		cout << "~Person()���������ĵ���" << endl;
	}

	int age;
	int* m_height;
};

int main01() {
	Person p1(10, 180);
	Person p2(p1);
	cout << "p1:����=" << p1.age << "�����=" << *p1.m_height << endl;
	cout << "p2:����=" << p2.age << "�����=" << *p2.m_height << endl;
	return 0;
}