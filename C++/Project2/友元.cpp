#include<iostream>
using namespace std;

class Building;
class GoodGay
{
public:
	GoodGay();

	void visit();		//参观函数，访问Building中的属性
	void visit2();
	Building* building;

};

//建筑物类
class Building
{
	//goodGay全局函数和GoodGay类和成员函数visit2是Building好朋友，可以访问Building中私有成员
	friend void goodGay(Building& building);
	friend class GoodGay;
	friend void GoodGay::visit2();

public:
	Building() {
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}

	string m_SittingRoom;	

private:
	string m_BedRoom;
};





//全局函数
void goodGay(Building &building) {
	cout << "好基友的全局函数正在访问：" << building.m_SittingRoom << endl;
	cout << "好基友的全局函数正在访问：" << building.m_BedRoom<< endl;		//全局函数要想访问类中的私有成员需在类中声明并加关键字friend
}


//类外实现成员函数
GoodGay::GoodGay() {
	//创建建筑物
	building = new Building;
}
void GoodGay::visit() {
	cout << "好基友1类正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友1类正在访问：" << building->m_BedRoom << endl;			//其它类要想访问类中的私有成员需在类中声明并加关键字friend
}
void GoodGay::visit2() {
	cout << "好基友2类正在访问：" << building->m_SittingRoom << endl;
	cout << "好基友2类正在访问：" << building->m_BedRoom << endl;			//成员函数要想访问类中的私有成员需在类中声明并加关键字friend
}


int main06() {
	Building building;
	goodGay(building);

	GoodGay gg;
	gg.visit();
	gg.visit2();
	return 0;
}