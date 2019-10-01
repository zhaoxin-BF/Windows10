#include <iostream>
using namespace std;

///////////////////////////
//unique_ptr的简单实现

template<class T>
class Unique_ptr
{
public:
	Unique_ptr(T* ptr=nullptr)
		:_ptr(ptr)
	{}
	~Unique_ptr()
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

private:
	Unique_ptr(const Unique_ptr<T>&) = delete;
	Unique_ptr<T>& operator=(const Unique_ptr<int>&) = delete;
protected:
	T* _ptr;
};

void TestUniquePtr()
{
	Unique_ptr<int> q(new int);
	*q = 10;
	cout << *q << endl;
}