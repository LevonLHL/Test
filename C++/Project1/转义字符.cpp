#include <iostream>
// #include <string.h>包含在了#include <iostream>里
using namespace std;

int main2() {
	cout << "hello world\n";
	cout << "\\" <<endl;
	cout << "aaa\thell" << endl;			//“\t”八个空格补齐
	cout << "aaaaa\thell" << endl;

	char str[] = "hello world";
	cout << str << endl;
	string str2 = "hello world";
	cout << str2 << endl;

	bool flag = true;
	cout << flag << endl;
	cout << "布尔类型所占空间：" << sizeof(flag) << endl;

	int a = 0;
	cout << "请给整型变量a赋值：" << endl;
	cin >> a;										//cin>>数据的输入
	cout << "a的值为：" << a << endl;
	string str3 = "hello";
	cout << "请给字符串str3赋值：" << endl;
	cin >> str3;
	cout << "str3的值为：" << str3 << endl;


	return 0;
}