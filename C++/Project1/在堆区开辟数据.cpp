#include<iostream>
using namespace std;

int* func() {
	//利用new关键字，可以将数据开辟到堆区
	//new返回的是该数据类型的指针
	int* p = new int(10);
	return p;
}
int main9() {
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	//堆区的数据由程序员管理开辟和释放
	delete p;
	//cout << *p << endl;		内存已经被释放，再次访问是非法操作


	int* arr = new int[10];		//代表有10个元素的数组
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//释放堆区的数组，释放数组的时候要加[]才可以
	delete[] arr;
	
	return 0;
}