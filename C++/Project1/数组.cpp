#include<iostream>
using namespace std;

int main5() {
	int arr[5];
	int arr2[5] = { 10,20,30,40 };
	int arr3[] = { 90,80 };
	arr[0] = 1;
	cout << arr[0] << endl;
	cout << arr[1] << endl;
	cout << arr2[0] << endl;
	cout << arr2[4] << endl;
	cout << arr3[0] << endl;
	cout << arr3[2] << endl;

	cout << "arr占用的内存为：" << sizeof(arr) << endl;
	cout << "每个元素占用的内存为：" << sizeof(arr[0]) << endl;
	cout << "arr中元素个数为：" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "arr的首地址为：" << (int)arr << endl;
	cout << "arr第二个元素的地址为：" << (int)&arr[1] << endl;
	
	//二维数组的定义可以没有行号，一定要有列号
	int arr4[][4] = {
		{0},
		{1,3},
		{7}
	};
	cout << "arr4占用的内存为：" << sizeof(arr4) << endl;
	cout << "每个元素占用的内存为：" << sizeof(arr4[0][0]) << endl;
	cout << "arr4每一行占用的内存为：" << sizeof(arr4[0]) << endl;
	cout << "二维数组行数为：" << sizeof(arr4)/sizeof(arr4[0]) << endl;
	cout << "二维数组列数为：" << sizeof(arr4[0]) / sizeof(arr4[0][0]) << endl;
	return 0;
}