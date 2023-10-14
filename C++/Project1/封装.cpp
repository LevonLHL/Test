#include<iostream>
using namespace std;

//设计一个圆类，求圆的周长
const double PI = 3.14;
class Circle
{
	//访问权限		public（公共权限）  protected（保护权限）  private（私有权限）
public:

	//属性
	int m_r;
	//行为
	//获取圆的周长
	double calculateZC() {
		return 2 * PI * m_r;
	}
};

//学生类
class Students
{
public:

	int m_Id;
	string m_Name;
	void showStudent() {
		cout << "姓名：" << m_Name << "\t学号：" << m_Id << endl;
	}

	//给姓名赋值
	void setName(string name) {
		m_Name = name;
	}
};


class Person
{
public:
	//公共权限（struct的默认权限）
	string m_Name;
protected:
	//保护权限
	string m_Car;
private:
	//私有权限（class默认权限）		1、可以自己控制读写权限。2、对于写可以检测数据的有效性。
	int m_Password;

public:
	void func() {
		m_Name = "张三";
		m_Car = "拖拉机";
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
		//m_Age = 0;		//初始化为0
		return m_Age;
	}
	void setAge(int age) {		//可读可写（0~100）
		if (age < 0 || age>100) {
			m_Age = 0;
			cout << "年龄输入有误" << endl;
			return;
		}
		m_Age = age;
	}
	void setLover(string lover) {
		m_Lover = lover;
	}

private:
	string m_Name;		//可读可写
	int m_Age;			//只读
	string m_Lover;		//只写
};


int main12() {
	//通过圆类创建具体的圆（对象）
	//实例化
	Circle c1;
	//给圆对象的属性进行赋值
	c1.m_r = 10;
	cout << "圆的周长为：" << c1.calculateZC() << endl;

	Students s1;
	s1.m_Id = 1;
	s1.m_Name = "张三";
	s1.showStudent();
	Students s2;
	s2.m_Id = 2;
	s2.m_Name = "李四";
	s2.showStudent();
	s1.setName("王五");
	s1.showStudent();

	Person p1;
	p1.m_Name = "李四";
	//p1.m_Car = "奔驰";	保护权限和私有权限内容，在类外访问不到
	//m_Password = 123456789;

	Person2 p;
	p.setName("张三");
	cout << "姓名为：" << p.getName() << endl;
	cout << "年龄为：" << p.getAge() << endl;
	p.setLover("苍劲");
	p.setAge(1000);
	cout << "年龄为：" << p.getAge() << endl;
	return 0;
}