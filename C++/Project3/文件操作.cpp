#include<iostream>
#include<string>
#include<fstream>				//���ļ����������ͷ�ļ�
using namespace std;


//д�ļ�
void test01() {
	//����������		ofstreamд����  ifstream������  fstream��д����
	ofstream ofs;
	//ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);			//ios::out��д�ļ��ķ�ʽ��  ios::in�Զ��ļ��ķ�ʽ��
	//д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;
	//�ر��ļ�
	ofs.close();
}
//���ļ�
void test02() {
	ifstream ifs;
	ifs.open("test.txt", ios::in);
	if (!ifs.is_open()) {					//�ж��ļ��Ƿ�򿪳ɹ�
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	//������
	/*��һ��
	char buf[1024] = { 0 };
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/
	/*�ڶ���
	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}*/
	//������
	string buf;
	while (getline(ifs,buf))
	{
		cout << buf << endl;
	}
	/*������	һ��һ���ֽڶ���Ч�ʽϵ�
	char c;
	while ((c = ifs.get()) != EOF)			//EOF��end of file
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
//�������ļ�д�ļ�
void test03() {
	ofstream ofs("person.txt", ios::out | ios::binary);			//ios::binary�Զ������ļ���
	Person p = { "����",20 };
	//д�ļ�
	ofs.write((const char*)&p, sizeof(Person));
	ofs.close();
}
//�������ļ����ļ�
void test04() {
	ifstream ifs("person.txt", ios::in | ios::binary);		
	if (!ifs.is_open()) {					//�ж��ļ��Ƿ�򿪳ɹ������ص��ǲ�������
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	Person p;
	//���ļ�
	ifs.read((char*)&p, sizeof(Person));
	cout << "������" << p.m_Name << "  ���䣺" << p.m_Age << endl;
	ifs.close();
}


int main1() {
	test01();
	test02();
	test03();
	test04();
	return 0;
}