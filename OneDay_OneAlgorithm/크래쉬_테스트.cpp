#include <iostream>

class EEEEEEEEEEEEEEE
{
	public:
	int eeeee;
};

void Func_EE(EEEEEEEEEEEEEEE* ee)
{
	ee->eeeee = 0;
}

class A
{
private:
	int aa;
	int bb;

public:
	void Func(EEEEEEEEEEEEEEE* ee)
	{ 
		Func_EE(ee);
	}
};

int main()
{
	EEEEEEEEEEEEEEE ee;

	A* mA = nullptr;
	mA->Func( &ee );	// ũ���� ���� ����

	std::cout << "hi" << "\n";
}