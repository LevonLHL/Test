#include<iostream>
using namespace std;

class Building;
class GoodGay
{
public:
	GoodGay();

	void visit();		//�ιۺ���������Building�е�����
	void visit2();
	Building* building;

};

//��������
class Building
{
	//goodGayȫ�ֺ�����GoodGay��ͳ�Ա����visit2��Building�����ѣ����Է���Building��˽�г�Ա
	friend void goodGay(Building& building);
	friend class GoodGay;
	friend void GoodGay::visit2();

public:
	Building() {
		m_SittingRoom = "����";
		m_BedRoom = "����";
	}

	string m_SittingRoom;	

private:
	string m_BedRoom;
};





//ȫ�ֺ���
void goodGay(Building &building) {
	cout << "�û��ѵ�ȫ�ֺ������ڷ��ʣ�" << building.m_SittingRoom << endl;
	cout << "�û��ѵ�ȫ�ֺ������ڷ��ʣ�" << building.m_BedRoom<< endl;		//ȫ�ֺ���Ҫ��������е�˽�г�Ա���������������ӹؼ���friend
}


//����ʵ�ֳ�Ա����
GoodGay::GoodGay() {
	//����������
	building = new Building;
}
void GoodGay::visit() {
	cout << "�û���1�����ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "�û���1�����ڷ��ʣ�" << building->m_BedRoom << endl;			//������Ҫ��������е�˽�г�Ա���������������ӹؼ���friend
}
void GoodGay::visit2() {
	cout << "�û���2�����ڷ��ʣ�" << building->m_SittingRoom << endl;
	cout << "�û���2�����ڷ��ʣ�" << building->m_BedRoom << endl;			//��Ա����Ҫ��������е�˽�г�Ա���������������ӹؼ���friend
}


int main06() {
	Building building;
	goodGay(building);

	GoodGay gg;
	gg.visit();
	gg.visit2();
	return 0;
}