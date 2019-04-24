#include <iostream>

using namespace std;

class programer
{
public:
	virtual void getSal() = 0;
};

//��������Ա
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

//�м�����Ա
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

//�߼�����Ա
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

//�ܹ�ʦ
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
	junior_programer jp("С��", "����", 4000);
	mid_programer mp("С��", "�м�", 8600);
	adv_programer ap("С��", "�߼�", 15000);
	
	//ϵͳ��չ
	architect ar("����", "�ܹ�ʦ", 20000);
	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);

	CalProgSal(&ar);
	system("pause");
	return 0;
}