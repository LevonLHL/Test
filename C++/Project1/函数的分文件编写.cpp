#include<iostream>
using namespace std;
#include "swap.h"




int main7() {
	int a = 10;
	int b = 20;
	swap(a, b);

	//��32λ����ϵͳ�£�ָ��ռ4�ֽڣ�����ʲô����
	//��64λ����ϵͳ�£�ָ��ռ8�ֽڣ�����ʲô����
	cout << "sizeof(int *)=" << sizeof(int *) << endl;
	cout << "sizeof(float *)=" << sizeof(float *) << endl;
	cout << "sizeof(double *)=" << sizeof(double *) << endl;
	cout << "sizeof(char *)=" << sizeof(char *) << endl;

	//��ָ�벻�ܽ��з��ʣ�0~255֮����ڴ�����ϵͳռ�ã��������ڸ�ָ�������ʼ����
	int* p = NULL;
	//*p = 100;

	//Ұָ�룬ͬ�����ʻ����
	int* p2 = (int*)0x1100;
	//cout << *p << endl;

	//����ָ�룺ָ���ָ������޸ģ�����ָ��ָ���ֵ�����޸�
	const int* p3 = &a;
	//ָ�볣����ָ���ָ�����޸ģ�����ָ��ָ���ֵ�����޸�
	int* const p4 = &a;
	//ָ���ָ���ָ��ָ���ֵ�������޸�
	const int* const p5 = &a;
	return 0;
}