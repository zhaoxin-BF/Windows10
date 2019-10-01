#include <iostream>
#include <mutex>
using namespace std;

template<class T>
class Shared_ptr
{
public:
	Shared_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		, _pCount(nullptr)
		, _pMutex(nullptr)
	{
		if (_ptr)
		{
			_pCount = new int(1);
			_pMutex = new mutex;
		}
	}

	~Shared_ptr()
	{
		Release();
	}

	Shared_ptr(const Shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		, _pCount(sp._pCount)
		, _pMutex(sp._pMutex)
	{
		if (_ptr)
		{
			IncreaseRefCount();
			//*++(*_pCount);
		}
	}

	//s1, s2
	//s1 = s2
	Shared_ptr<T>& operator=(const Shared_ptr<T>& sp)
	{
		if (this != &sp)
		{
			Release();

			_ptr = sp._ptr;
			_pCount = sp._pCount;

			if (sp._ptr)
			{
				IncreaseRefCount();
				//++(*_pCount);
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

	void IncreaseRefCount()
	{
		_pMutex->lock();
		++(*_pCount);
		_pMutex->unlock();
	}

	int DecreaseRefCount()
	{
		_pMutex->lock();
		--(*_pCount);
		_pMutex->unlock();

		return *_pCount;
	}

	void Release()
	{
		if (_ptr && 0 == DecreaseRefCount())
		{
			delete _ptr;
			delete _pCount;
			delete _pMutex;

			_ptr = nullptr;
			_pCount = nullptr;
			_pMutex = nullptr;
		}
	}

protected:
	T* _ptr;
	int* _pCount;
	mutex* _pMutex;
};