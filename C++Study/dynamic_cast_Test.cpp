#include <string>
using namespace std;

class Base
{
public:
	void baseFunc();
};

class De : public Base
{
public:
	virtual void Func();
};

int main()
{
	// ���̳��� ĳ��Ʈ�� �θ� Ŭ������ ���� �Լ��� ���� ���, �ٿ� ĳ���� �Ұ���.
	Base* b = new De;
	dynamic_cast<De*>(b)->Func();

	// �׷���, �� ĳ������ ������.
	De* d = new De;
	dynamic_cast<Base*>(d)->baseFunc();

	int a = 0;
	string str = static_cast<string>(a);
	float f = static_cast<float>(a);


	return 0;
}