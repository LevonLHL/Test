#pragma once
#include"Identity.h"

//ѧ����
class Student : public Identity
{
public:
	Student();
	Student(int id, string name, string pwd);//�вι��죺ѧ�š�����������
	virtual void operMenu();//�˵�����
	void applyOrder();//����ԤԼ
	void showMyOrder();//�鿴����ԤԼ
	void showAllOrder();//�鿴����ԤԼ
	void cancelOrder();//ȡ��ԤԼ

	int m_Id;//ѧ��ѧ��
	vector<ComputerRoom>vCom;//��������
};
