#include <iostream>
using namespace std;

//////////////////////////////
//auto_ptr 的实现
template<class T>
class Autoptr
{
public:
	Autoptr(T* ptr = nullptr)
		:_ptr(ptr)
	{}

	//拷贝构造：将ap的资源转移到当前对象_ptr上
	Autoptr(Autoptr<T>& ap)
		:_ptr(ap._ptr)
	{
		ap._ptr = nullptr;
	}
	//赋值操作
	Autoptr<T>& operator=(Autoptr<T>& ap)
	{
		if (this != &ap)
		{
			if (_ptr)
				delete _ptr;
			_ptr = ap._ptr;
			ap._ptr = nullptr;
		}
		return *this;
	}

	~Autoptr()
	{
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T* Get()
	{
		return _ptr;
	}

	void ReSet(T* ptr)
	{
		if (_ptr)
			delete _ptr;
		_ptr = ptr;
	}
protected:
	T* _ptr;
};

struct A
{
	int a;
	int b;
	int c;
};

void TestAutoPtr()
{
	Autoptr<int> ap1(new int);
	*ap1 = 10;

	Autoptr<A> ap2(new A);
	ap2->a = 1;
	ap2->b = 2;
	ap2->c = 3;

	Autoptr<int> ap3(new int);
	*ap3 = 12;
	int cc = 12;
	int* ap4 = &cc;

	ap1.ReSet(ap4);

	cout << *ap1 << endl;
}