#include <iostream>
using namespace std;

template<class T>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		, _pCount(nullptr)
	{
		if (_ptr)
		{
			_pCount = new int(1);
		}
	}
	Shared_ptr(const Shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		, _pCount(sp._pCount)
	{
		if (_ptr)
			++(*_pCount);
	}

	Shared_ptr<T>& operator=(const Shared_ptr<T>& sp)
	{
		if (this != &sp)
		{
			if (_ptr && --(*_pCount))
			{
				delete _ptr;
				delete _pCount;
			}
			_ptr = sp._ptr;
			_pCount = sp._pCount;

			if (sp._ptr)
			{
				++(*_pCount);
			}
		}
		return *this;
	}

	int use_Count()
	{
		return *_pCount;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	~Shared_ptr()
	{
		if (_ptr && 0 == --(*_pCount))
		{
			delete _ptr;
			delete _pCount;
			_ptr = nullptr;
			_pCount = nullptr;
		}
	}
protected:
	T* _ptr;
	int* _pCount;
};

void TestShared_ptr()
{
	Shared_ptr<int> p(new int);
	cout << p.use_Count() << endl;

	cout << *p << endl;

	Shared_ptr<int> p2(p);
	cout << p.use_Count() << endl;
}

//int main()
//{
//	TestShared_ptr();
//	return 0;
//}