#include<iostream>
using namespace std;

struct Student {
	string name;
	int age;
	int score;
}s3;

//�ṹ��Ƕ��
struct Teacher
{
	int id;
	string name;
	int age;
	struct Student stu;
};


void PrintStudent1(struct Student s) {
	s.age = 100;
	cout << "����printStudent1�ڴ�ӡ��" << endl;
	cout << "������" << s.name << "	���䣺" << s.age << "	������" << s.score << endl;
}

//�βθ�Ϊָ��ĺô��ǿ��Լ����ڴ�ռ䣨һ��ָ��ֻռ4�ֽڣ����Ҳ��Ḵ���µĸ���������
void PrintStudent2(const struct Student * p) {
	//p->age = 100;				//	const��ֹ�����              
	cout << "����printStudent2�ڴ�ӡ��" << endl;
	cout << "������" << p->name << "	���䣺" << p->age << "	������" << p->score << endl;
}


int main8() {
	//�����ṹ�����ʱstruct�ؼ��ֿ�ʡ��
	Student s1; 
	s1.age = 18;
	s1.name = "����";
	s1.score = 100;
	cout << "������" << s1.name << "	���䣺" << s1.age << "	������" << s1.score << endl;
	struct Student s2 = { "����",19,80 };
	cout << "������" << s2.name << "	���䣺" << s2.age << "	������" << s2.score << endl;
	s3.age = 20;
	s3.name = "����";
	s3.score = 99;
	cout << "������" << s3.name << "	���䣺" << s3.age << "	������" << s3.score << endl;

	//�ṹ������
	struct Student arr[3] = {
		{"����",30,60},
		{ "����",19,80 },
		{ "����",19,80 }
	};
	arr[2].score = 99;
	for (int i = 0; i < 3; i++)
	{
		cout << "������" << arr[i].name << "	���䣺" << arr[i].age << "	������" << arr[i].score << endl;
	}

	//�ṹ��ָ��(��->����)
	Student* p = &s1;
	cout << "������" << p->name << "	���䣺" << p->age << "	������" << p->score << endl;

	Teacher t;
	t.id = 10000;
	t.age = 50;
	t.name = "����";
	t.stu.name = "С��";
	t.stu.age = 20;
	t.stu.score = 60;
	cout << "��ʦ������" << t.name << "	��ʦ���䣺" << t.age << "	��ʦid��" << t.id << endl;
	cout << "��ʦ������ѧ��������" << t.stu.name << "	��ʦ������ѧ�����䣺" << t.stu.age << "	��ʦ������ѧ��������" << t.stu.score << endl;

	//�ṹ������������
	PrintStudent1(s1);
	cout << "������" << s1.name << "	���䣺" << s1.age << "	������" << s1.score << endl;
	PrintStudent2(&s1);
	cout << "������" << s1.name << "	���䣺" << s1.age << "	������" << s1.score << endl;

	//�ṹ���е�const

	return 0;
}