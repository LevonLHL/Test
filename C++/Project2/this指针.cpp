#include<iostream>
using namespace std;


//thisָ�룺1��������Ƴ�ͻ��2�����ض������� *this��
class Person
{
public:
	Person(int age) {
		//thisָ��ָ�򱻵��õĳ�Ա���������Ķ���
		this->age = age;
	}
	Person& PersonAddAge(Person p) {
		this->age += p.age;
		return *this;		//���ض���������������ʽ���˼��Ĳ���
	}


	//��ָ����ó�Ա����
	void showClassName() {
		cout << "this is person class" << endl;
	}
	void showPersonAge() {
		if (this == NULL)	return;					//����ǰ���п�ָ����ж�
		cout << "age=" << m_Age << endl;			//����m_Ageǰ����Ĭ����this->�ģ����������ԭ���Ǵ����ָ��ΪNULL
	}


	//������
	void showPerson() const							//��Ա���������const�����ε���thisָ���൱��const Person * const this����ָ���ֵҲ�����޸���
	{
		//m_Age = 100;								//ͬ��������thisָ�롣thisָ��ı�����ָ�볣����Person * const this����ָ���ָ���ǲ����޸ĵ�
		m_B = 100;
	}


	int age;
	int m_Age;
	mutable int m_B;				//�����������ʹ�ڳ������У�Ҳ�����޸����ֵ�����Ϲؼ���mutable
};

int main05() {
	Person p1(10);
	cout << "p1�����䣺" << p1.age << endl;

	Person p2(18);
	cout << "p2�����䣺" << p2.age << endl;
	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);			//��ʽ���˼��
	cout << "p2�����䣺" << p2.age << endl;

	Person* p3 = NULL;
	p3->showClassName();
	p3->showPersonAge();

	p1.showPerson();
	cout << "p1��m_B��" << p1.m_B << endl;
	//������
	const Person p4(100);							//����ǰ��const����Ϊ������
	//p4.m_Age = 100;								//�������ֵ���ɸ���
	p4.m_B = 100;									//m_B����mutable�ؼ��ֿ����޸�
	//������ֻ�ܵ��ó�����
	p4.showPerson();
	//p4.showPersonAge();
	return 0;
}