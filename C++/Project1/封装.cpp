#include<iostream>
using namespace std;

//���һ��Բ�࣬��Բ���ܳ�
const double PI = 3.14;
class Circle
{
	//����Ȩ��		public������Ȩ�ޣ�  protected������Ȩ�ޣ�  private��˽��Ȩ�ޣ�
public:

	//����
	int m_r;
	//��Ϊ
	//��ȡԲ���ܳ�
	double calculateZC() {
		return 2 * PI * m_r;
	}
};

//ѧ����
class Students
{
public:

	int m_Id;
	string m_Name;
	void showStudent() {
		cout << "������" << m_Name << "\tѧ�ţ�" << m_Id << endl;
	}

	//��������ֵ
	void setName(string name) {
		m_Name = name;
	}
};


class Person
{
public:
	//����Ȩ�ޣ�struct��Ĭ��Ȩ�ޣ�
	string m_Name;
protected:
	//����Ȩ��
	string m_Car;
private:
	//˽��Ȩ�ޣ�classĬ��Ȩ�ޣ�		1�������Լ����ƶ�дȨ�ޡ�2������д���Լ�����ݵ���Ч�ԡ�
	int m_Password;

public:
	void func() {
		m_Name = "����";
		m_Car = "������";
		m_Password = 123456;
	}

};

class Person2
{
public:
	void setName(string name) {
		m_Name = name;
	}
	string getName() {
		return m_Name;
	}
	int getAge() {		
		//m_Age = 0;		//��ʼ��Ϊ0
		return m_Age;
	}
	void setAge(int age) {		//�ɶ���д��0~100��
		if (age < 0 || age>100) {
			m_Age = 0;
			cout << "������������" << endl;
			return;
		}
		m_Age = age;
	}
	void setLover(string lover) {
		m_Lover = lover;
	}

private:
	string m_Name;		//�ɶ���д
	int m_Age;			//ֻ��
	string m_Lover;		//ֻд
};


int main12() {
	//ͨ��Բ�ഴ�������Բ������
	//ʵ����
	Circle c1;
	//��Բ��������Խ��и�ֵ
	c1.m_r = 10;
	cout << "Բ���ܳ�Ϊ��" << c1.calculateZC() << endl;

	Students s1;
	s1.m_Id = 1;
	s1.m_Name = "����";
	s1.showStudent();
	Students s2;
	s2.m_Id = 2;
	s2.m_Name = "����";
	s2.showStudent();
	s1.setName("����");
	s1.showStudent();

	Person p1;
	p1.m_Name = "����";
	//p1.m_Car = "����";	����Ȩ�޺�˽��Ȩ�����ݣ���������ʲ���
	//m_Password = 123456789;

	Person2 p;
	p.setName("����");
	cout << "����Ϊ��" << p.getName() << endl;
	cout << "����Ϊ��" << p.getAge() << endl;
	p.setLover("�Ծ�");
	p.setAge(1000);
	cout << "����Ϊ��" << p.getAge() << endl;
	return 0;
}