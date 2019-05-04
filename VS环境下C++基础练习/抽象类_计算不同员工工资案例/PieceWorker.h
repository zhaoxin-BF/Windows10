#pragma once

#include <iostream>
#include "Employee.h"
using namespace std;

class PieceWorker :public Employee
{
public:
	PieceWorker(const long num, const char* name, double wageperpice = 0.0, int quantity = 0) :Employee(num, name)
	{
		this->wagePerPice = wageperpice;
		this->quantity = quantity;
	}
	void setWage(double wageperpice)
	{
		this->wagePerPice = wageperpice;
	}
	void setQuantity(int quantity)
	{
		this->quantity = quantity;
	}
	virtual double earnings()
	{
		return this->wagePerPice*this->quantity;
	}
	virtual void print()
	{
		cout << this->getNumber() << "PieceWorker" << this->getName() << this->earnings() << endl;
	}
private:
	double wagePerPice;
	int quantity;
};


