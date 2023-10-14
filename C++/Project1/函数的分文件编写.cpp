#include<iostream>
using namespace std;
#include "swap.h"




int main7() {
	int a = 10;
	int b = 20;
	swap(a, b);

	//在32位操作系统下，指针占4字节，不管什么类型
	//在64位操作系统下，指针占8字节，不管什么类型
	cout << "sizeof(int *)=" << sizeof(int *) << endl;
	cout << "sizeof(float *)=" << sizeof(float *) << endl;
	cout << "sizeof(double *)=" << sizeof(double *) << endl;
	cout << "sizeof(char *)=" << sizeof(char *) << endl;

	//空指针不能进行访问（0~255之间的内存编号是系统占用），是用于给指针变量初始化的
	int* p = NULL;
	//*p = 100;

	//野指针，同样访问会出错
	int* p2 = (int*)0x1100;
	//cout << *p << endl;

	//常量指针：指针的指向可以修改，但是指针指向的值不能修改
	const int* p3 = &a;
	//指针常量：指针的指向不能修改，但是指针指向的值可以修改
	int* const p4 = &a;
	//指针的指向和指针指向的值都不能修改
	const int* const p5 = &a;
	return 0;
}