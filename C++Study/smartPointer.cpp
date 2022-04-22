#include <iostream>

int main()
{
	int* p1 = 0;
	int* p2 = NULL;
	int* p3 = nullptr;

	// ������ ������ �ʱ�ȭ�ϱ� ���� ������ ��Ĵ�� 0, NULL�� ����ص� ������
	// nullptr�� ����ϴ� ���� �����ϰ� �ڵ��� �������� ���� �� �ִ�.

	// nullptr�� ������ Ÿ��
	// std::nullptr_t Ÿ��
}

///////////////////////////
//using
#include <unordered_map>
#include <string>
#include <memory>

int main()
{
	typedef std::unique_ptr < std::unordered_map < std::string, std::string>> UPtrMapSS;

	// ���� ������ �ڵ���, �� �������ִ�.
	using UPtrMapSS = std::unique_ptr < std::unordered_map < std::string, std::string>>;

	// 1. �����ϱ� ����.
	typedef void (*FP)(int, const std::string&);	// typedef
	using FP = void (*)(int, const std::string&);	// ��Ī ����(alias)

	// 2. typedef�� ���ø�ȭ�� �� �� ������ ��Ī ������ ���ø�ȭ�� �� �ִ�.
	// typedef

}

class Widget {};

template <typename T>
struct My
{
	typedef std::list<T, My<T>> type;
};

template <typename T>
using Myall = std::list<T, My<T>>;

int main()
{
	My<Widget>::type lw;

	Myall<Widget> lw;
}

//////////////////////////////////////////////
////////////////////////////////////////////////
// �������� ������
// �����Ͱ� ����Ű�� �ּ��� ���� �迭���� �ϳ��� ��ü���� �Ǻ��� �Ұ��� -> ������ ������ Ÿ��
// �ı��ϱ� ���� � ����� ����� �� �˾Ƴ� ����� ����. delete�� �������, delete[]�� �������
// �����Ͱ� ����Ű�� ����� ���� �����ϰ� �ִ��� �ƴ��� �� �� �ִ� ����� ����. -> ��Ÿ�� ������
// ��۸� ������(dangling pointer), �ڿ��� �̹� ������ �ڿ����� �ƴ��� �Ǻ��� �� ����.
// �ڿ� ������ ��Ȯ�� �� ���� �ؾ��Ѵ�. -> �ߺ� ���� ���� ���

// C++11 ���ʹ� ������ ���� ���ο� ����Ʈ �����͸� �����Ѵ�.
// unique_ptr : ��Ÿ�� ������
// shared_ptr : ���� �ڿ� ����
// weak_ptr : shared_ptr ����
using namespace std;

class Foo
{
public:
	Foo() { std::cout << "����\n"; }
	~Foo() { std::cout << "�Ҹ�\n"; }
};

int main()
{
	Foo* ptr = new Foo();
	delete ptr;

	unique_ptr<Foo> sptr(new Foo());				// ��ü 2�� ����
	unique_ptr<Foo> ssptr = make_unique<Foo>();		// C++14

	// �������� �ʾƵ� �ڵ����� �Ҹ�ȴ�.

	// �� ������ �۵��Ѵ�.
	{
		unique_ptr<Foo> ptr2 = make_unique<Foo>();
		// ����� ����� ���� ptr2 ����, �޸�����, �Ҹ��� ȣ��...
	}

	{
		new
		throw	// throw������ �� ������ ������, delete ȣ�� X
		delete
	}

}

/////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
// RAII ����
// Resource Acquisition Is Initialization
// �ڿ��� ȹ���� �ʱ�ȭ��
// ���ÿ� �Ҵ�� �޸𸮴� �ڵ����� �����Ǵ� ���� �̿��� ������ ����
