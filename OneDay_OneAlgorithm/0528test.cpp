#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Base
{
public:
	void Func() { cout << "Base Func()" << '\n'; };
};

class Derived : public Base
{
public:
	void Func() { cout << "Dervied Func()" << '\n'; }
	void DerivedFunc() { cout << "sdfsdf\n"; }
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	// �ǹ� : �������̵��� �θ� Ŭ������ ��� �Լ��� ������ �ϴ� ���ε�,
	//		 ���� �Լ��� �ƴ� ��� �Լ��� ������ �ϴ� �͵� �������̵��ΰ�?
	//		 -> å�� ���� ���������� ���ݾ� �ٸ���. ��ǰ C++�� ���� �Լ��� �������ϴ� ���� �������̵��̶�� ���ϰ� �ִ�.

	Base* d = new Derived;
	d->Func();

	delete d;

	// �ǹ� 2 : dynamic_cast�ÿ� ��� ���迡 ������ ���� �Լ��� �ϳ��� ������ ������ ������ �߻��ϴ°�?
	// -> �߻��Ѵ�. �������� ���� ��ü������ �����Ѵ�.
	dynamic_cast<Derived*>(d)->DerivedFunc();

	return 0;
}