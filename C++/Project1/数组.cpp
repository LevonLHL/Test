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

	cout << "arrռ�õ��ڴ�Ϊ��" << sizeof(arr) << endl;
	cout << "ÿ��Ԫ��ռ�õ��ڴ�Ϊ��" << sizeof(arr[0]) << endl;
	cout << "arr��Ԫ�ظ���Ϊ��" << sizeof(arr) / sizeof(arr[0]) << endl;
	cout << "arr���׵�ַΪ��" << (int)arr << endl;
	cout << "arr�ڶ���Ԫ�صĵ�ַΪ��" << (int)&arr[1] << endl;
	
	//��ά����Ķ������û���кţ�һ��Ҫ���к�
	int arr4[][4] = {
		{0},
		{1,3},
		{7}
	};
	cout << "arr4ռ�õ��ڴ�Ϊ��" << sizeof(arr4) << endl;
	cout << "ÿ��Ԫ��ռ�õ��ڴ�Ϊ��" << sizeof(arr4[0][0]) << endl;
	cout << "arr4ÿһ��ռ�õ��ڴ�Ϊ��" << sizeof(arr4[0]) << endl;
	cout << "��ά��������Ϊ��" << sizeof(arr4)/sizeof(arr4[0]) << endl;
	cout << "��ά��������Ϊ��" << sizeof(arr4[0]) / sizeof(arr4[0][0]) << endl;
	return 0;
}