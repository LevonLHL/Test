#include <iostream>
// #include <string.h>��������#include <iostream>��
using namespace std;

int main2() {
	cout << "hello world\n";
	cout << "\\" <<endl;
	cout << "aaa\thell" << endl;			//��\t���˸��ո���
	cout << "aaaaa\thell" << endl;

	char str[] = "hello world";
	cout << str << endl;
	string str2 = "hello world";
	cout << str2 << endl;

	bool flag = true;
	cout << flag << endl;
	cout << "����������ռ�ռ䣺" << sizeof(flag) << endl;

	int a = 0;
	cout << "������ͱ���a��ֵ��" << endl;
	cin >> a;										//cin>>���ݵ�����
	cout << "a��ֵΪ��" << a << endl;
	string str3 = "hello";
	cout << "����ַ���str3��ֵ��" << endl;
	cin >> str3;
	cout << "str3��ֵΪ��" << str3 << endl;


	return 0;
}