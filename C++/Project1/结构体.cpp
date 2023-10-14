#include<iostream>
using namespace std;

struct Student {
	string name;
	int age;
	int score;
}s3;

//结构体嵌套
struct Teacher
{
	int id;
	string name;
	int age;
	struct Student stu;
};


void PrintStudent1(struct Student s) {
	s.age = 100;
	cout << "函数printStudent1内打印：" << endl;
	cout << "姓名：" << s.name << "	年龄：" << s.age << "	分数：" << s.score << endl;
}

//形参改为指针的好处是可以减少内存空间（一个指针只占4字节，而且不会复制新的副本出来）
void PrintStudent2(const struct Student * p) {
	//p->age = 100;				//	const防止误操作              
	cout << "函数printStudent2内打印：" << endl;
	cout << "姓名：" << p->name << "	年龄：" << p->age << "	分数：" << p->score << endl;
}


int main8() {
	//创建结构体变量时struct关键字可省略
	Student s1; 
	s1.age = 18;
	s1.name = "张三";
	s1.score = 100;
	cout << "姓名：" << s1.name << "	年龄：" << s1.age << "	分数：" << s1.score << endl;
	struct Student s2 = { "李四",19,80 };
	cout << "姓名：" << s2.name << "	年龄：" << s2.age << "	分数：" << s2.score << endl;
	s3.age = 20;
	s3.name = "王五";
	s3.score = 99;
	cout << "姓名：" << s3.name << "	年龄：" << s3.age << "	分数：" << s3.score << endl;

	//结构体数组
	struct Student arr[3] = {
		{"张三",30,60},
		{ "李四",19,80 },
		{ "王五",19,80 }
	};
	arr[2].score = 99;
	for (int i = 0; i < 3; i++)
	{
		cout << "姓名：" << arr[i].name << "	年龄：" << arr[i].age << "	分数：" << arr[i].score << endl;
	}

	//结构体指针(用->访问)
	Student* p = &s1;
	cout << "姓名：" << p->name << "	年龄：" << p->age << "	分数：" << p->score << endl;

	Teacher t;
	t.id = 10000;
	t.age = 50;
	t.name = "老王";
	t.stu.name = "小王";
	t.stu.age = 20;
	t.stu.score = 60;
	cout << "教师姓名：" << t.name << "	教师年龄：" << t.age << "	教师id：" << t.id << endl;
	cout << "教师辅导的学生姓名：" << t.stu.name << "	教师辅导的学生年龄：" << t.stu.age << "	教师辅导的学生分数：" << t.stu.score << endl;

	//结构体做函数参数
	PrintStudent1(s1);
	cout << "姓名：" << s1.name << "	年龄：" << s1.age << "	分数：" << s1.score << endl;
	PrintStudent2(&s1);
	cout << "姓名：" << s1.name << "	年龄：" << s1.age << "	分数：" << s1.score << endl;

	//结构体中的const

	return 0;
}