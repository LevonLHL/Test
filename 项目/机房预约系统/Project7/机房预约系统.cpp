#include<iostream>
using namespace std;
#include"Identity.h"


int main() {
	int select = 0;//�����û�ѡ��
	while (true)
	{
		Menu();
		cin >> select;
		switch (select)
		{
		case 1:		//ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:		//��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:		//����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:		//�˳�
			Exit();
			exit(0);
			break;
		default:
			cout << "������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}