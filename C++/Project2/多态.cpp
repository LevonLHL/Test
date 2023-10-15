#include<iostream>
using namespace std;

/*
静态多态：函数重载，运算符重载...
动态多态：1、有继承关系。2、子类重写（返回类型、函数名、参数都相同）父类的虚函数。（覆盖操作）
	动态多态的使用：父类的指针或者引用指向子类对象。
*/

//动物类
class Animal
{
public:
	virtual void speak() {								//地址晚绑定：在函数前加关键字virtual，变为虚函数
		cout << "动物在说话" << endl;
	}
	Animal() {
		cout << "Animal的构造函数调用" << endl;
	}
	//虚析构
	//virtual ~Animal() {									//利用虚析构可以解决父类指针释放子类对象时不干净的问题，如果子类中没有堆区数据可以不写。
	//	cout << "Animal的纯析构函数调用" << endl;
	//}
	virtual ~Animal() = 0;							//纯虚析构，需要声明也需要有实现，防止父类也有属性开辟到堆区。有了纯虚析构之后，这个类也属于抽象类，无法实例化对象。
};
Animal::~Animal()
{
	cout << "Animal的纯虚析构函数调用" << endl;			//也可留空，但一定要写，只在类内写纯虚析构的声明virtual ~Animal() = 0;会报错
}
//猫类
class Cat :public Animal
{
public:
	void speak() {
		cout << *m_Name << "小猫在说话" << endl;
	}


	Cat(string name) {
		cout << "Cat的构造函数调用" << endl;
		m_Name = new string(name);
	}
	~Cat() {
		if (m_Name != NULL) {
			cout << "Cat的析构函数调用" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}

	string* m_Name;
};
//狗类
class Dog :public Animal
{
public:
	void speak() {
		cout << "小狗在说话" << endl;
	}
};

//地址早绑定：在编译阶段确定函数地址
//如果想执行让猫说话，那么这个函数地址就不能提前绑定，需要在运行阶段进行绑定，即地址晚绑定
void doSpeak(Animal& animal) {			//Animal &animal = cat
	animal.speak();
}

int main10() {
	Cat cat("Tom");
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);

	cout << "sizeof Animal = " << sizeof(Animal) << endl;			//存储的是一个指针 vfptr - 虚函数（表）指针，当发生继承时有这个指针也会被继承下来，当发生重写时这个指针也会被覆盖
	
	Animal* animal = new Cat("Tom");
	animal->speak();					//正常情况下父类指针在析构的时候不会调用子类中的析构函数，导致子类如果有堆区属性，出现内存泄漏。解决办法：写虚析构或纯虚析构。
	delete animal;
	return 0;
}