#include<iostream>
using namespace std;


//��Ա�����ͳ�Ա�����ֿ��洢

class Person2 {

};

class Person3 {
	int m_A;			//�Ǿ�̬��Ա�����������������
	static int m_B;		//��̬��Ա�������������������
	void func() {		//�Ǿ�̬��Ա������������������ϣ���̬��Ա����ͬ��

	}
};
int Person3::m_B = 0;

class Person
{
public:

	//��̬��Ա���������еĶ�����ͬһ����������̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
	static void func() {
		m_A = 0;
		//m_C = 200;		��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
		cout << "static void func����" << endl;
	}


	//��̬��Ա����
	/*1�����ж��󶼹���ͬһ������
	* 2������׶ξͷ����ڴ�
	* 3�����������������ʼ������
	*/
	static int m_A;

	//��̬��Ա�����;�̬��Ա����Ҳ���з���Ȩ�޵�
private:
	static void func2() {
		cout << "static void func2����" << endl;
	}

	static int m_B;
	int m_C;
};
int Person::m_A = 100;
int Person::m_B = 300;

void test03()
{
	Person p;
	cout << p.m_A << endl;
	Person p2;
	p2.m_A = 200;
	cout << p.m_A << endl;
}

void test04() {
	//��̬��Ա����������ĳ�������ϣ����ж��󶼹���ͬһ������
	//��˾�̬��Ա���������ַ��ʷ�ʽ
	// 1��ͨ��������з���
	Person p;
	cout << p.m_A << endl;
	// 2��ͨ���������з���
	cout << Person::m_A << endl;
	//cout << Person::m_B << endl;		������ʲ���
}

void test05() {
	//1.ͨ���������
	Person p;
	p.func();
	//2.ͨ����������
	Person::func();
	//Person::func2();					������ʲ���
}

int main03() {
	test03();
	test04();
	test05();

	Person2 p;
	cout << "size of p=" << sizeof(p) << endl;		//�ն���ռ�õ��ڴ�ռ�Ϊ 1��Ϊ�����ֶ������ڴ��λ�á�
	Person3 p1;
	cout << "size of p1=" << sizeof(p1) << endl;
	return 0;
}