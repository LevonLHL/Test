#include<iostream>
using namespace std;

//������Ĭ�ϲ���,�д����ô��룬û������Ĭ��
int func(int a,int b=20,int c=30) {			//���ĳ��λ���Ѿ�����Ĭ�ϲ�������ô�����λ������Ӧ����Ĭ�ϲ���
	return a + b + c;
}
//�������������Ĭ�ϲ������Ǻ�����ʵ�־Ͳ�����Ĭ�ϲ���
int func2(int a=10, int b=10);
int func2(int a, int b) {		
	return a + b;
}


//������ռλ����,ռλ������������Ĭ�ϲ�����:void test(int = 10)
void test(int a,int) {
	cout << "This is test" << endl;
}


//�������أ�1��ͬһ���������¡�2������������ͬ��3�������������Ͳ�ͬ���߸�����ͬ����˳��ͬ��
void test01() {
	cout << "This is test01" << endl;
}
/*   �����ķ���ֵ��������Ϊ�������ص�����
int test01() {
	cout << "This is test01" << endl;
}
*/
void test01(int a) {
	cout << "This is test01(int a)" << endl;
}
void test01(double a) {
	cout << "This is test01(double a)" << endl;
}
void test01(int a,double b) {
	cout << "This is test01(int a,double b)" << endl;
}
void test01(double a,int b) {
	cout << "This is test01(double a,int b)" << endl;
}

//������Ϊ���ص�����
void test02(int &a) {
	cout << "This is test02(int &a)" << endl;
}
void test02(const int& a) {
	cout << "This is test02(const int &a)" << endl;
}
//������������Ĭ�ϲ���
void test03(int a,int b=10) {
	cout << "This is test03(int a,int b=10)" << endl;
}
void test03(int a) {
	cout << "This is test03(int a)" << endl;
}

int main11() {
	cout << func(10) << endl;
	cout << func(10,30) << endl;
	cout << func2(30) << endl;

	test(1,10);

	test01();
	test01(1);
	test01(3.14);
	test01(2, 3.14);
	test01(10.0, 10);

	int a = 10;
	test02(a);
	test02(10);

	//test03(20);	//���ֶ����Ա���
	test03(10, 20);
	return 0;
}