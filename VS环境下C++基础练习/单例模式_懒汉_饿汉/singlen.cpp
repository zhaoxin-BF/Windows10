class Singlen
{
public:
	static Singlen* getInstance();
	~Singlen() {}
private:
	Singlen(){}
	Singlen(const Singlen& obj) = delete;
	Singlen& operator=(const Singlen& obj) = delete;

	static Singlen* m_pSinglen
};
//懒汉单例模式(非线程安全的)
Singlen* Singlen::m_pSinglen = NULL;

Singlen* Singlen::getInstance()
{
	if (m_pSinglen == NULL)
	{
		m_pSinglen = new Singlen();
	}
	return m_pSinglen;
}


//懒汉单例模式(线程安全的)
std::mutex mt;
Singlen* Singlen::m_pSinglen = NULL;

Singlen* Singlen::getInstance()
{
	if (m_pSinglen == NULL)
	{
		mt.lock();
		if (m_pSinglen == NULL)
		{
			m_pSinglen = new Singlen();
		}
		mt.unlock();
	}
	return m_pSinglen();
}



///饿汉单例模式
Singlen* Singlen::m_pSinglen = new Singlen();

Singlen* Singlen::getInstance()
{
	return m_pSinglen;
}