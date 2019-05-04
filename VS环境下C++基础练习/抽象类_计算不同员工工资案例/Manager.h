#pragma once

#include <iostream>
#include "Employee.h"
using namespace std;

class Manager : public Employee
{
public:
	Manager(const long num, const char* name, double salary= 0.0) :Employee(num, name)
	{
		this->monthlySalary = salary;
	}
	void setMonthlySalary(double salary)
	{
		this->monthlySalary = salary;
	}
	virtual double earnings()
	{
		return this->monthlySalary;
	}
	virtual void print()
	{
		cout << this->getNumber() << "Manager" << this->getName() << this->earnings() << endl;
	}
private:
	double monthlySalary;
};


