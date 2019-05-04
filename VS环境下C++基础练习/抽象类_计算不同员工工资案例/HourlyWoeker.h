#pragma once

#include <iostream>
#include "Employee.h"
using namespace std;

class HourlyWorker : public Employee
{
public:
	HourlyWorker(long num, char* name, double wage = 0.0, int hour = 0) :Employee(num,name)
	{
		this->wage = wage;
		this->hours = hour;
	}
	void setWage(double wage)
	{
		this->wage = wage;
	}
	void setHours(int hour)
	{
		this->hours = hour;
	}
	virtual double earnings()
	{
		return this->wage*this->hours;
	}
	virtual void print()
	{
		cout << this->getNumber() << "HourWorker" << this->getName() << this->earnings() << endl;
	}
private:
	double wage;
	double hours;
};


