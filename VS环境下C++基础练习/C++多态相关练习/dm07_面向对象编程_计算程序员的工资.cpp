#include <iostream>

using namespace std;

class programer
{
public:
	virtual void getSal() = 0;
};

//初级程序员
class junior_programer : public programer
{
public:
	junior_programer(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;

};

//中级程序员
class mid_programer : public programer
{
public:
	mid_programer(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;

};

//高级程序员
class adv_programer : public programer
{
public:
	adv_programer(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;

};

//架构师
class architect : public programer
{
public:
	architect(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
private:
	char *name;
	char *job;
	int sal;

};

void CalProgSal(programer *base)
{
	base->getSal();
}


int main()
{
	junior_programer jp("小王", "初级", 4000);
	mid_programer mp("小张", "中级", 8600);
	adv_programer ap("小李", "高级", 15000);
	
	//系统扩展
	architect ar("赵鑫", "架构师", 20000);
	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);

	CalProgSal(&ar);
	system("pause");
	return 0;
}