#include <iostream>

class A
{
public:
	A() { Test(); }
	virtual ~A() { }
	virtual void Test() {}
};

class B : public A
{
public:
	B() {}
	virtual ~B() {}
	virtual void Test() {}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	A* pA = new B();

	delete pA;

	return 0;
}