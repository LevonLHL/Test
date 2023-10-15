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
//�����̳У�private��Ա���ɷ��ʣ�������Աû�б仯��
class Son1 :public Base1
{
public:
	void func() {
		m_A = 10;		//�����еĹ���Ȩ�޳�Ա����������Ȼ�ǹ�����Ա
		m_B = 10;		//�����еı���Ȩ�޳�Ա����������Ȼ�Ǳ�����Ա
		//m_C = 10;		//�����е�˽��Ȩ�޳�Ա������ʲ���
	}

	int m_D;
};
//�����̳У�private��Ա���ɷ��ʣ�������Ա��Ϊprotected��
class Son2 :protected Base1
{
public:
	void func() {
		m_A = 10;		//�����еĹ���Ȩ�޳�Ա�������б�Ϊ������Ա
		m_B = 10;		//�����еı���Ȩ�޳�Ա����������Ȼ�Ǳ�����Ա
		//m_C = 10;		//�����е�˽��Ȩ�޳�Ա������ʲ���
	}
};
//˽�м̳У�private��Ա���ɷ��ʣ�������Ա��Ϊprivate��
class Son3 :private Base1
{
public:
	void func() {
		m_A = 10;		//�����еĹ���Ȩ�޳�Ա�������б�Ϊ˽�г�Ա
		m_B = 10;		//�����еı���Ȩ�޳�Ա�������б�Ϊ˽�г�Ա
		//m_C = 10;		//�����е�˽��Ȩ�޳�Ա������ʲ���
	}
};

//Son3�Ĺ����̳�
class GrandSon3 :public Son3
{
public:
	void func() {			//����Son3��m_A��m_B��m_C��Ϊ˽�У����Ƕ��ӣ�Ҳ�Ƿ��ʲ���
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
		cout << "Base - func()����" << endl;
	}
	void func(int a) {
		cout << "Base - func(int a)����" << endl;
	}
	static void func1() {
		cout << "Base - static void func1()����" << endl;
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
		cout << "Son - func()����" << endl;
	}
	static void func1() {
		cout << "Son - static void func1()����" << endl;
	}

	int m_A;
	static int m_B;
};
int Base::m_B = 100;
int Son::m_B = 200;


//������̳н�����μ̳����⣺�̳�֮ǰ���Ϲؼ���virtual��Ϊ��̳У���Ϊ��̳к�Animal���Ϊ�����
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
	//s1.m_B = 100;			//��Son1�е�m_B�Ǳ���Ȩ��������ʲ���
	Son2 s2;
	//s2.m_A = 100;			//��Son2�е�m_A��Ϊ�˱���Ȩ��������ʲ���
	//s2.m_B = 100;			//��Son2�е�m_B�Ǳ���Ȩ��������ʲ���
	Son3 s3;
	//s3.m_A = 100;			//��Son3�е�m_A��Ϊ��˽��Ȩ��������ʲ���
	//s3.m_B = 100;			//��Son3�е�m_B��Ϊ��˽��Ȩ��������ʲ���

	cout << "size of Son1 = " << sizeof(Son1) << endl;			//���������зǾ�̬��Ա���Զ��ᱻ����̳���ȥ������private��Ա��������˽�г�Ա�����Ǳ������������ˣ�����Ƿ��ʲ���������ȷʵ���̳���ȥ�ˡ�
																//���ÿ�����Ա������ʾ���߲鿴����ģ�ͣ��ȵ��ļ�·���£�Ȼ�������cl /d1 reportSingleClassLayout���� "�ļ���"
	
	Son s;
	cout << "Son�µ� m_A = " << s.m_A << endl;
	cout << "Base�µ� m_A = " << s.Base::m_A << endl;			//ͬ����Ա�����ͨ�����������Ҫ���ʵ������е�ͬ����Ա��Ҫ��������
	s.func();													//ֱ�ӵ������ȵ�������ĳ�Ա����
	s.Base::func();												//ͬ��������Ҳ�����أ����������븸��ӵ��ͬ����Ա��������������ظ�����ͬ����Ա����������������Է��ʵ������е�ͬ������
	s.Base::func(1);
	cout << "ͨ��������ʾ�̬��Ա��" << endl;
	cout << "Son�µ� m_B = " << s.m_B << endl;					//ͬ����̬��Ա���ԣ�ͬ�ϣ�
	cout << "Base�µ� m_B = " << s.Base::m_B << endl;
	s.func1();													//ͬ����̬��Ա������ͬ�ϣ���Ҳ�����ظ�����ͬ����Ա����
	s.Base::func1();
	cout << "ͨ���������ʾ�̬��Ա��" << endl;
	cout << "Son�µ� m_B = " << Son::m_B << endl;
	cout << "Base�µ� m_B = " << Son::Base::m_B << endl;		//��һ��::����ͨ��������ʽ���ʡ��ڶ���::������ʸ�����������
	Son::func1();
	Son::Base::func1();

	SheepTuo st;
	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;	//�����μ̳в�����̳У���������ӵ����ͬ���ݣ���Ҫ�������������֣������ж����ԣ�������Դ�˷�
	cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
	cout << "st.m_Age = " << st.m_Age << endl;					//ʹ����̳к���Բ���������
	return 0;
}

//�̳��еĹ��������˳���ȹ��츸�࣬�ٹ������࣬������˳���빹���˳���෴��
//���ö��ű��ʽ����ʵ�ֶ�̳У���̳�����������г�����ͬ�����������ʹ��ʱҪ�������򣩡��﷨��class ����: �̳з�ʽ ����1, �̳з�ʽ ����2 ...
