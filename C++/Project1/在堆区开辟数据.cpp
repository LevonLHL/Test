#include<iostream>
using namespace std;

int* func() {
	//����new�ؼ��֣����Խ����ݿ��ٵ�����
	//new���ص��Ǹ��������͵�ָ��
	int* p = new int(10);
	return p;
}
int main9() {
	int* p = func();
	cout << *p << endl;
	cout << *p << endl;
	//�����������ɳ���Ա�����ٺ��ͷ�
	delete p;
	//cout << *p << endl;		�ڴ��Ѿ����ͷţ��ٴη����ǷǷ�����


	int* arr = new int[10];		//������10��Ԫ�ص�����
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 100;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	//�ͷŶ��������飬�ͷ������ʱ��Ҫ��[]�ſ���
	delete[] arr;
	
	return 0;
}