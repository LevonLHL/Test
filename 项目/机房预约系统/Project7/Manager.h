#pragma once
#include"Identity.h"

class Student;
class Teacher;

//����Ա��
class Manager :public Identity
{
public:
	Manager();
	Manager(string name, string pwd);//�вι��죺����������
	virtual void operMenu();//�˵�����
	void addPerson();//����˺�
	void showPerson();//�鿴�˺�
	void showComputer();//�鿴������Ϣ
	void cleanFile();//���ԤԼ��¼
	void initVector();//��ʼ������
	bool checkRepeat(int id, int type);//����ظ���ѧ����/ְ���ţ�ѧ��/��ʦ��

	vector<Student>vStu;//ѧ������
	vector<Teacher>vTea;//��ʦ����
	vector<ComputerRoom>vCom;//��������
};