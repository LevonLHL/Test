#pragma once
#include"Identity.h"


//��ʦ��
class Teacher : public Identity
{
public:
	Teacher();
	Teacher(int empId, string name, string pwd);//�вι��죺��š�����������
	virtual void operMenu();//�˵�����
	void showAllOrder();//�鿴����ԤԼ
	void validOrder();//���ԤԼ

	int m_EmpId;//��ʦ���
};