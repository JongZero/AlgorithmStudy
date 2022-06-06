/// ������ �ʱ�ȭ
//c++ 11 �������� Ÿ���� �ʱ�ȭ ����� �������� �ʾҴ�. 
// ���� ��� ������ ���� ���� ������ �� �� ���� ����ü��, �� ���� Ŭ������ �ۼ��� ��츦 ���캸��.
struct CircleStruct
{
	int x, y;
	double radius;
};

class CircleClass
{
public:
	CircleClass(int x, int y, double radius)
		: mX(x), mY(y), mRadius(radius) {}
private:
	int mX, mY;
	double mRadius;
};

// c++ 11 �������� CircleStruct Ÿ�� ������ CircleClass Ÿ�� ������ �ʱ�ȭ�ϴ� ����� ���� �޶���.
CircleStruct myCircle1 = { 10, 10, 2.5 };
CircleClass myCircle2(10, 10, 2.5);
// ����ü�� ���ؼ��� {...} ������ ������ �ݸ�, Ŭ������ ���ؼ��� �Լ� ǥ����� (...)�� �����ڸ� ȣ���ߴ�.
// �׷��� C++ 11 ���� Ÿ���� �ʱ�ȭ�� �� {...} ������ ����ϴ� ������ �ʱ�ȭ(���� �ʱ�ȭ, �߰�ȣ �ʱ�ȭ)�� �������� ���ϵƴ�.
CircleStruct myCircle3 = { 10, 10, 2.5 };
CircleClass myCircle4 = { 10, 10, 2.5 };
// myCircle4�� �����ϴ� ������ ����� �� CircleClass�� �����ڰ� �ڵ����� ȣ��ȴ�.
// ���� ������ ���� ��ȣ(=)�� �����ص� �ȴ�.
CircleStruct myCircle5{ 10, 10, 2.5 };
CircleClass myCircle6{ 10, 10, 2.5 };

// �̷��� ������ �̴ϼȶ������� ����ü�� Ŭ�����Ӹ� �ƴ϶� c++�� �ִ� ��� ����� �ʱ�ȭ�ϴ� �� ����ȴ�.
// ���� ��� ���� �ڵ�� �� ������ ��� 3�̶� ������ �ʱ�ȭ�Ѵ�.
int a = 3;
int b(3);
int c = { 3 };	// ������ �ʱ�ȭ
int d{ 3 };		// ������ �ʱ�ȭ

// ������ �ʱ�ȭ�� ������ �� �ʱ�ȭ(���� �ʱ�ȭ)�� ���� ������ �� �ִ�.
// ������ ���� �߰�ȣ�� �� ���� ǥ�ø� ���ָ� �ȴ�.
int e{};	// ������ �ʱ�ȭ, e�� 0�� �ȴ�.

// ������ �ʱ�ȭ�� ����ϸ� ��� ��ȯ(narrowing)�� ������ �� �ִ�.
// c++������ �Ϲ������� ��� ��ȯ�� ���� �ִµ�, ���� ��� ������ ����.
void func(int i) { }

int main()
{
	int x = 3.14;
	func(3.14);
}
// x�� ���� ������ ���� func()�� ȣ���� �� ������ 3.14�� 3���� ���� �پ���.
// �����Ϸ��� ���� �̷��� ����� ������ ��� �޽����� �߻��� ���� �ִ�. (��: MS ���־� ��Ʃ��� 2017 Ŀ�´�Ƽ �����)
// ������ �ʱ�ȭ�� ����ϸ� x�� ���� �����ϰų� func()�� ȣ���ϴ� ������ ��� �ڵ带 c++ 11 ǥ���� ������ �����ϴ� �����Ϸ��� �������ϸ�
// �ݵ�� ���� �޽����� �����ȴ�.
void func(int i) { }

int main()
{
	int x = { 3.14 };	// ��ҷ� ���� ����
	func({ 3.14 });		// ��ҷ� ���� ����
}

// ������ �ʱ�ȭ�� �������� �Ҵ�Ǵ� �迭�� �ʱ�ȭ�� ���� ������ �� �ִ�.
// ���� ��� ������ ����.
int* pArray = new int[4]{ 0, 1, 2, 3 };

// ���� Ŭ���� ����� �迭�� ������ �̴ϼȶ������� �ʱ�ȭ�� ���� ����� �� �ִ�.
class MyClass
{
public:
	MyClass() : mArray{ 0, 1, 2, 3 } {}
private:
	int mArray[4];
};

/// ���� ����Ʈ �ʱ�ȭ�� ���� ����Ʈ �ʱ�ȭ
// �̴ϼȶ������� ���� �� ������ ������, �̴ϼȶ����� ����Ʈ�� �߰�ȣ�� ��� ǥ���Ѵ�.
// ���� ����Ʈ �ʱ�ȭ(copy list initialization): T obj = {arg1, arg2, ...};
// ���� ����Ʈ �ʱ�ȭ(direct list initialization): T obj {arg1, arg2, ...};

// c++ 17 ���ʹ� auto Ÿ�� �߷� ��ɰ� �����Ͽ� ���� ����Ʈ �ʱ�ȭ�� ���� ����Ʈ �ʱ�ȭ�� ũ�� �޶�����.
// c++ 17 ���� (c++ 11/14)���� ���� ����Ʈ �ʱ�ȭ�� ���� ����Ʈ �ʱ�ȭ ��� initializer_list<>�� ó���ߴ�.
#include <initializer_list>
// ���� ����Ʈ �ʱ�ȭ
auto a = { 11 };		// initializer_list<int>
auto b = { 11, 22 };	// initializer_list<int>

// ���� ����Ʈ �ʱ�ȭ
auto c{ 11 };			// initializer_list<int>
auto d{ 11, 22 };		// initializer_list<int>

// c++ 17���ʹ� auto�� ���� ����Ʈ �ʱ�ȭ�� ���� �� �ϳ��� �߷��Ѵ�.
// ���� �� �ڵ带 �����ϸ� ������ �߻��Ѵ�.
// ���� ����Ʈ �ʱ�ȭ
auto a = { 11 };		// initializer_list<int>
auto b = { 11, 22 };	// initializer_list<int>

// ���� ����Ʈ �ʱ�ȭ
auto c{ 11 };			// int
auto d{ 11, 22 };		// ���Ұ� �ʹ� ���ٴ� ������ �߻��Ѵ�.

// ���� ����Ʈ �ʱ�ȭ���� �߰�ȣ �ȿ� ���� ���Ҵ� �ݵ�� Ÿ���� ��� ���ƾ� �Ѵ�.
// ���� ��� ������ ���� �ۼ��ϸ� ������ ������ �߻��Ѵ�.
auto b = { 11, 22.33 };		// �����Ͽ���

/// ù c++ ���α׷�
// ���� ���� �ý���
// ȸ�� ���� ������ �����ϴ� ���α׷��� ������ �����ϰ� ����� ���ؾ� �Ѵ�.
// �� ���α׷����� ������ ����� ������ ����.
// ���� ä��
// ���� �ذ�
// ���� ����
// ���ſ� ���� ���� ��� ��ȸ
// ���� ���� ��� ��ȸ
// ���� ���� ��� ��ȸ

// �� ���α׷��� ũ�� �� �κ����� �̷���� �ִ�.
// Employee Ŭ������ ���� �� �� ���� ������ ǥ���Ѵ�.
// Database Ŭ������ ȸ�翡 ���� ��� ������ �����Ѵ�.
// ���� �� ���α׷��� �ٷ�� ����� UserInterface�� �����Ѵ�.

// Employee Ŭ����
// Employee Ŭ������ ���� �� �� ���� ��� ������ �����Ѵ�.
#pragma once
#include <string>

// namespace Records�� �� ���α׷����� ���ø����̼ǿ� Ưȭ�� �ڵ忡 ���� ���ӽ����̽���.
namespace Records
{
	// �� å������ ��� �̸��� ���� �� ����� �ǹ��ϴ� ���Ͼ� Konstant�� ù ������ 'k'�� ��� �տ� ���̴� ���ʸ� ������.
	const int kDefaultStartingSalary = 30000;

	class Employee
	{
	public:
		Employee() = default;
		Employee(const std::string& firstName,
				const std::string& lastName);

		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire();	// ������ ä���ϰų� ���ӿ��Ѵ�.
		void fire();	// ������ �ذ��Ѵ�.
		void display() const;	// ���� ������ �ֿܼ� ����Ѵ�.

		// ���Ϳ� ����
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool isHired() const;

	private:
		std::string mFirstName;
		std::string mLastName;
		int mEmployeeNumber = -1;
		int mSalary = kDefaultStartingSalary;
		bool mHired = false;
	};
}



