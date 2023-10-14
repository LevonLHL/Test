#include<iostream>
using namespace std;

int main4() {
	int num;
	cout << "请打分：";
	cin >> num;
	switch (num)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		cout << "烂片" << endl;
		break;
	case 5:
	case 6:
		cout << "一般" << endl;
		break;
	case 7:
	case 8:
		cout << "非常好" << endl;
		break;
	case 9:
	case 10:
		cout << "经典" << endl;
		break;
	default:
		break;
	}
	srand((unsigned int)time(NULL));	//添加随机数种子，利用时间生成随机数
	int a = rand()%100+1;			//生成随机数
	cout << "a=" << a << endl;

	return 0;
}