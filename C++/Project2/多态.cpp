#include<iostream>
using namespace std;

/*
��̬��̬���������أ����������...
��̬��̬��1���м̳й�ϵ��2��������д���������͡�����������������ͬ��������麯���������ǲ�����
	��̬��̬��ʹ�ã������ָ���������ָ���������
*/

//������
class Animal
{
public:
	virtual void speak() {								//��ַ��󶨣��ں���ǰ�ӹؼ���virtual����Ϊ�麯��
		cout << "������˵��" << endl;
	}
	Animal() {
		cout << "Animal�Ĺ��캯������" << endl;
	}
	//������
	//virtual ~Animal() {									//�������������Խ������ָ���ͷ��������ʱ���ɾ������⣬���������û�ж������ݿ��Բ�д��
	//	cout << "Animal�Ĵ�������������" << endl;
	//}
	virtual ~Animal() = 0;							//������������Ҫ����Ҳ��Ҫ��ʵ�֣���ֹ����Ҳ�����Կ��ٵ����������˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ��������
};
Animal::~Animal()
{
	cout << "Animal�Ĵ���������������" << endl;			//Ҳ�����գ���һ��Ҫд��ֻ������д��������������virtual ~Animal() = 0;�ᱨ��
}
//è��
class Cat :public Animal
{
public:
	void speak() {
		cout << *m_Name << "Сè��˵��" << endl;
	}


	Cat(string name) {
		cout << "Cat�Ĺ��캯������" << endl;
		m_Name = new string(name);
	}
	~Cat() {
		if (m_Name != NULL) {
			cout << "Cat��������������" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}

	string* m_Name;
};
//����
class Dog :public Animal
{
public:
	void speak() {
		cout << "С����˵��" << endl;
	}
};

//��ַ��󶨣��ڱ���׶�ȷ��������ַ
//�����ִ����è˵������ô���������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣�����ַ���
void doSpeak(Animal& animal) {			//Animal &animal = cat
	animal.speak();
}

int main10() {
	Cat cat("Tom");
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);

	cout << "sizeof Animal = " << sizeof(Animal) << endl;			//�洢����һ��ָ�� vfptr - �麯������ָ�룬�������̳�ʱ�����ָ��Ҳ�ᱻ�̳���������������дʱ���ָ��Ҳ�ᱻ����
	
	Animal* animal = new Cat("Tom");
	animal->speak();					//��������¸���ָ����������ʱ�򲻻���������е�����������������������ж������ԣ������ڴ�й©������취��д����������������
	delete animal;
	return 0;
}