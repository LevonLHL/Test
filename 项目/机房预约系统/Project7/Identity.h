#pragma once
#include<iostream>
using namespace std;
#include"GlobalFile.h"
#include<fstream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include"ComputerRoom.h"
#include"OrderFile.h"


void Menu();
void Exit();
void LoginIn(string fileName, int type);//��¼���ܣ������������ļ���������������ͣ�



//��ݳ������
class Identity
{
public:
	virtual void operMenu() = 0;//�����˵�


	string m_Name;	//�û���
	string m_Pwd;	//����
};

void managerMenu(Identity*& manager);//�������Ա�Ӳ˵�����
void studentMenu(Identity*& student);//����ѧ���Ӳ˵�����
void teacherMenu(Identity*& teacher);//�����ʦ�Ӳ˵�����
//���������ļ�����Ҫ�������Ҫ���࣬����������ں�����൱�ڻ���û���κ��������ʱ���C2504��δ����Ļ���
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
void printStudent(Student& s);//��ӡѧ��
void printTeacher(Teacher& t);//��ӡ��ʦ
void printComputerRoom(ComputerRoom& c);//��ӡ����