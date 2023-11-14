#include"Manager.h"


Manager::Manager() {

}

Manager::Manager(string name, string pwd) {
	this->m_Name = name;
	this->m_Pwd = pwd;
	//��ʼ������ ��ȡ�������ļ��е�ѧ������ʦ��Ϣ
	this->initVector();
	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom com;
	while (ifs>>com.m_ComId && ifs>>com.m_MaxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	//����
	cout << "����������Ϊ��" << vCom.size() << endl;
}

void Manager::operMenu() {
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t------------------����--\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      1.����˺�      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      2.�鿴�˺�      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      3.�鿴����      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      4.���ԤԼ      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      0.ע����¼      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t--------------����------\n";
	cout << "���������Ĳ�����";
}

void Manager::addPerson() {
	string fileName;//�����ļ���
	string tip;//��ʾid��
	ofstream ofs;//�ļ���������
	int select = 0;
	while (true)
	{
		cout << "����������˺ŵ����ͣ�" << endl;
		cout << "1�����ѧ��" << endl;
		cout << "2����ӽ�ʦ" << endl;
		cin >> select;
		if (select == 1)//���ѧ��
		{
			fileName = STUDENT_FILE;
			tip = "������ѧ�ţ�";
			break;
		}
		else if (select == 2)//��ӽ�ʦ
		{
			fileName = TEACHER_FILE;
			tip = "������ְ���ţ�";
			break;
		}
		else
		{
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			this->operMenu();
		}
	}
	ofs.open(fileName, ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�
	int id;
	string name;
	string pwd;
	while (true)
	{
		cout << tip;
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
		{
			cout << "���ظ����ݣ����������룡" << endl;
		}
		else
		{
			break;
		}
	}
	
	cout << "������������";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;
	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;
	ofs.close();
	//���ó�ʼ�������Ľӿڣ����»�ȡ�ļ��е�����
	this->initVector();
	system("pause");
	system("cls");
}

void Manager::showPerson() {
	while (true)
	{
		cout << "��ѡ��鿴�����ݣ�" << endl;
		cout << "1���鿴����ѧ��" << endl;
		cout << "2���鿴���н�ʦ" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)//�鿴ѧ��
		{
			cout << "���е�ѧ����Ϣ���£�" << endl;
			for_each(vStu.begin(), vStu.end(), printStudent);
			system("pause");
			system("cls");
			return;
		}
		else if (select == 2)//�鿴��ʦ
		{
			cout << "���еĽ�ʦ��Ϣ���£�" << endl;
			for_each(vTea.begin(), vTea.end(), printTeacher);
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			this->operMenu();
		}
	}
}

void Manager::showComputer() {
	cout << "��������Ϣ���£�" << endl;
	for_each(vCom.begin(), vCom.end(), printComputerRoom);
	system("pause");
	system("cls");
}

void Manager::cleanFile() {
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector() {
	//ȷ���������״̬
	vStu.clear();
	vTea.clear();
	//��ȡ��Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	Student s;
	while (ifs>>s.m_Id && ifs>>s.m_Name && ifs>>s.m_Pwd)
	{
		vStu.push_back(s);
	}
	//����
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	//����
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();
}

bool Manager::checkRepeat(int id, int type) {
	if (type == 1)//���ѧ��
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
				return true;
		}
	}
	else    //����ʦ
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
				return true;
		}
	}
	return false;
}