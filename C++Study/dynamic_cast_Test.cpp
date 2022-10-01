#include <string>
using namespace std;

class Base
{
public:
	virtual void Func();
};

class De : public Base
{
public:
	virtual void Func();
};

int main()
{
	Base* b = new De;
	dynamic_cast<De*>(b)->Func();

	int a = 0;
	string str = static_cast<string>(a);
	float f = static_cast<float>(a);


	return 0;
}