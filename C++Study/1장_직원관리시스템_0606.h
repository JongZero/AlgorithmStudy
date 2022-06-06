/// 첫 c++ 프로그램
// 직원 관리 시스템
// 회사 직원 정보를 관리하는 프로그램은 구조가 유연하고 기능이 편리해야 한다.
// 이 프로그램에서 제공할 기능은 다음과 같다.
// 직원 채용
// 직원 해고
// 직원 승진
// 과거와 현재 직원 모두 조회
// 현재 직원 모두 조회
// 과거 직원 모두 조회

// 이 프로그램은 크게 세 부분으로 이루어져 있다.
// Employee 클래스는 직원 한 명에 대한 정보를 표현한다.
// Database 클래스는 회사에 속한 모든 직원을 관리한다.
// 또한 이 프로그램을 다루는 기능은 UserInterface로 정의한다.

// Employee 클래스
// Employee 클래스는 직원 한 명에 대한 모든 정보를 관리한다.
#pragma once
#include <string>

// namespace Records는 이 프로그램에서 애플리케이션에 특화된 코드에 대한 네임스페이스다.
namespace Records
{
	// 이 책에서는 상수 이름을 정할 때 상수를 의미하는 독일어 Konstant의 첫 글자인 'k'를 상수 앞에 붙이는 관례를 따른다.
	const int kDefaultStartingSalary = 30000;

	class Employee
	{
	public:
		Employee() = default;
		Employee(const std::string& firstName,
			const std::string& lastName);

		void promote(int raiseAmount = 1000);
		void demote(int demeritAmount = 1000);
		void hire();	// 직원을 채용하거나 재임용한다.
		void fire();	// 직원을 해고한다.
		void display() const;	// 직원 정보를 콘솔에 출력한다.

		// 게터와 세터
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