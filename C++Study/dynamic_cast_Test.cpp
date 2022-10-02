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
	// 다이나믹 캐스트는 부모 클래스에 가상 함수가 없는 경우, 다운 캐스팅 불가능.
	Base* b = new De;
	dynamic_cast<De*>(b)->Func();

	// 그러나, 업 캐스팅은 가능함.
	De* d = new De;
	dynamic_cast<Base*>(d)->baseFunc();

	int a = 0;
	string str = static_cast<string>(a);
	float f = static_cast<float>(a);


	return 0;
}