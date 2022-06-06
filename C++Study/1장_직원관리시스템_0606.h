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