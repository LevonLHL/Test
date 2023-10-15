#include<iostream>
using namespace std;


//����ͬ�����
//����CPU��
class CPU
{
public:
	//����ļ��㺯��
	virtual void calculate() = 0;
};
//�����Կ���
class VideoCard
{
public:
	//����ļ��㺯��
	virtual void display() = 0;
};
//�����ڴ�����
class Memory
{
public:
	//����ļ��㺯��
	virtual void storage() = 0;
};

//������
class Computer
{
public:
	Computer(CPU* cpu, VideoCard* vc, Memory* mem) {
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}
	//�ṩ�����ĺ���
	void work() {
		//���ýӿ�
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}
	~Computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}

private:
	CPU* m_cpu;			//CPU�����ָ��
	VideoCard* m_vc;		//�Կ����ָ��
	Memory* m_mem;		//�ڴ������ָ��
};

//���峧��
//Intel����
class IntelCPU :public CPU
{
public:
	virtual void calculate() {
		cout << "Intel��CPU��ʼ����" << endl;
	}
};
class IntelVideoCard :public VideoCard
{
public:
	virtual void display() {
		cout << "Intel���Կ���ʼ����" << endl;
	}
};
class IntelMemory :public Memory
{
public:
	virtual void storage() {
		cout << "Intel���ڴ�����ʼ����" << endl;
	}
};
//Lenovo����
class LenovoCPU :public CPU
{
public:
	virtual void calculate() {
		cout << "Lenovo��CPU��ʼ����" << endl;
	}
};
class LenovoVideoCard :public VideoCard
{
public:
	virtual void display() {
		cout << "Lenovo���Կ���ʼ����" << endl;
	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage() {
		cout << "Lenovo���ڴ�����ʼ����" << endl;
	}
};



int main() {
	//��һ̨�������
	CPU* intelCpu = new IntelCPU;
	VideoCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;
	//������һ̨����
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;

	cout << "------------------" << endl;
	//��װ�������ڶ�̨����
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;
	cout << "------------------" << endl;
	//��װ����������̨����
	Computer* computer3 = new Computer(new LenovoCPU, new IntelVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
	return 0;
}