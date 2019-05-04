#pragma once

#include <iostream>
using namespace std;

class Employee
{
public:
	Employee(const long num,const char* name)
	{
		this->number = num;
		this->name = name;
	}
	const char* getName()
	{
		return this->name;
	}
	const long getNumber()
	{
		return this->number;
	}
	virtual double earnings()
	{
		return 0.0;
	}
	virtual void print()
	{
		cout << "¹¤×Ê" << this->earnings() << endl;
	}
public:
	long number;
	const char* name;
};


