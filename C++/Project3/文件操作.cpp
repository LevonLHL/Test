#include<iostream>
#include<string>
#include<fstream>				//对文件操作需包含头文件
using namespace std;


//写文件
void test01() {
	//创建流对象		ofstream写操作  ifstream读操作  fstream读写操作
	ofstream ofs;
	//指定打开方式
	ofs.open("test.txt", ios::out);			//ios::out以写文件的方式打开  ios::in以读文件的方式打开
	//写内容
	ofs << "姓名：张三" << endl;
	ofs << "性别：男" << endl;
	ofs << "年龄：18" << endl;
	//关闭文件
	ofs.close();
}
//读文件
void test02() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {					//判断文件是否打开成功
		cout << "文件打开失败" << endl;
		return;
	}
	//读数据
	/*第一种
	char buf[1024] = { 0 };
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/
	/*第二种
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	//第三种
	string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}
	/*第四种	一个一个字节读，效率较低
	char c;
	while ((c = ifs.get()) != EOF)			//EOF：end of file
	{
		cout << c;
	}*/
	ifs.close();
}


class Person
{
public:

	char m_Name[64];
	int m_Age;
};
//二进制文件写文件
void test03() {
	ofstream ofs("person.txt", ios::out | ios::binary);			//ios::binary以二进制文件打开
	Person p = { "李四",20 };
	//写文件
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}
//二进制文件读文件
void test04() {
	ifstream ifs("person.txt", ios::in | ios::binary);		
	if (!ifs.is_open()) {					//判断文件是否打开成功，返回的是布尔类型
		cout << "文件打开失败" << endl;
		return;
	}
	Person p;
	//读文件
	ifs.read((char*)&p, sizeof(Person));
	cout << "姓名：" << p.m_Name << "  年龄：" << p.m_Age << endl;
	ifs.close();
}


int main1() {
	test01();
	test02();
	test03();
	test04();
	return 0;
}