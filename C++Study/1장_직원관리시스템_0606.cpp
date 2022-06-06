#include <iostream>
#include "1장_직원관리시스템_0606.h"

using namespace std;

namespace Records
{
	Employee::Employee(const std::string& firstName,
		const std::string& lastName)
		: mFirstName(firstName), mLastName(lastName)
	{
	}


	void Employee::promote(int raiseAmount /*= 1000*/)
	{
		setSalary(getSalary() + raiseAmount);
	}

	void Employee::demote(int demeritAmount /*= 1000*/)
	{
		setSalary(getSalary() - demeritAmount);
	}

	void Employee::hire()
	{
		mHired = true;
	}

	void Employee::fire()
	{
		mHired = false;
	}

	void Employee::display() const
	{
		cout << "Employee : " << getLastName() << ", " << getFirstName() << endl;
		cout << "---------------------------" << endl;
		cout << (isHired() ? "Current Employee" : "Former Employee") << endl;
		cout << "Employee Number : " << getEmployeeNumber() << endl;
		cout << "Salary : $" << getSalary() << endl;
		cout << endl;
	}

	void Employee::setFirstName(const std::string& firstName)
	{
		mFirstName = firstName;
	}

	const std::string& Employee::getFirstName() const
	{
		return mFirstName;
	}

	void Employee::setLastName(const std::string& lastName)
	{
		mLastName = lastName;
	}

	const std::string& Employee::getLastName() const
	{
		return mLastName;
	}

	void Employee::setEmployeeNumber(int employeeNumber)
	{
		mEmployeeNumber = employeeNumber;
	}

	int Employee::getEmployeeNumber() const
	{
		return mEmployeeNumber;
	}

	void Employee::setSalary(int newSalary)
	{
		mSalary = newSalary;
	}

	int Employee::getSalary() const
	{
		return mSalary;
	}

	bool Employee::isHired() const
	{
		return mHired;
	}
}