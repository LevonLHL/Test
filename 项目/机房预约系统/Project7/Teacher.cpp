#include"Teacher.h"

Teacher::Teacher() {

}

Teacher::Teacher(int empId, string name, string pwd) {
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMenu() {
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t------------------——--\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      1.查看所有预约  |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      2.审核预约      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t|      0.注销登录      |\n";
	cout << "\t\t|                      |\n";
	cout << "\t\t--------------——------\n";
	cout << "请输入您的操作：";
}

void Teacher::showAllOrder() {
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["date"];
		cout << "	时间段：" << ((of.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
		cout << "	学号：" << of.m_orderData[i]["stuId"];
		cout << "	姓名：" << of.m_orderData[i]["stuName"];
		cout << "	机房号：" << of.m_orderData[i]["roomId"];
		string status = "	状态：";//1 审核中 2 已预约 -1 预约失败 0 取消预约 
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "预约失败，审核未通过！";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::validOrder() {
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录！" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int>v;
	int index = 0;
	cout << "待审核的预约记录如下：" << endl;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << ++index << "、";
			cout << "预约日期：周" << of.m_orderData[i]["date"];
			cout << "	时间段：" << ((of.m_orderData[i]["interval"] == "1") ? "上午" : "下午");
			cout << "	学号：" << of.m_orderData[i]["stuId"];
			cout << "	姓名：" << of.m_orderData[i]["stuName"];
			cout << "	机房号：" << of.m_orderData[i]["roomId"];
			cout << "	状态：审核中" << endl;
		}
	}
	cout << "请输入审核的预约记录，0代表返回：";
	int select = 0;//接收用户选择的预约记录
	int ret = 0;//接收预约结果记录
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				cout << "请输入审核的结果" << endl;
				cout << "1、通过" << endl;
				cout << "2、不通过" << endl;
				while (true)
				{
					cin >> ret;
					if (ret == 1)//通过
					{
						of.m_orderData[v[select - 1]]["status"] = "2";
						break;
					}
					else if(ret == 2)//不通过
					{
						of.m_orderData[v[select - 1]]["status"] = "-1";
						break;
					}
					cout << "输入有误，请重新输入！" << endl;
				}
				of.updateOrder();//更新预约记录
				cout << "审核完毕！" << endl;
				break;
			}
		}
		cout << "输入有误，请重新输入！" << endl;
	}
	system("pause");
	system("cls");
}