#include<iostream>
using namespace std;

int main4() {
	int num;
	cout << "���֣�";
	cin >> num;
	switch (num)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		cout << "��Ƭ" << endl;
		break;
	case 5:
	case 6:
		cout << "һ��" << endl;
		break;
	case 7:
	case 8:
		cout << "�ǳ���" << endl;
		break;
	case 9:
	case 10:
		cout << "����" << endl;
		break;
	default:
		break;
	}
	srand((unsigned int)time(NULL));	//�����������ӣ�����ʱ�����������
	int a = rand()%100+1;			//���������
	cout << "a=" << a << endl;

	return 0;
}