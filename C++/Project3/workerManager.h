#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	WorkerManager();
	//�˵�
	void Show_Menu();
	//�˳�
	void ExitSystem();
	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//ͳ���ļ�������
	int get_EmpNum();
	//��ʼ��ְ��
	void init_Emp();
	//��ʾְ��
	void Show_Emp();
	//ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ���� ���ڷ��������±� �����ڷ���-1
	int IsExist(int id);
	//�޸�ְ��
	void Mod_Emp();
	//����ְ��
	void Find_Emp();
	//����
	void Sort_Emp();
	//���
	void Clean_File();

	~WorkerManager();


	//��¼ְ������
	int m_EmpNum;
	//ְ������ָ��
	Worker** m_EmpArray;
	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
};