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
//��������ģʽ(���̰߳�ȫ��)
Singlen* Singlen::m_pSinglen = NULL;

Singlen* Singlen::getInstance()
{
	if (m_pSinglen == NULL)
	{
		m_pSinglen = new Singlen();
	}
	return m_pSinglen;
}


//��������ģʽ(�̰߳�ȫ��)
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



///��������ģʽ
Singlen* Singlen::m_pSinglen = new Singlen();

Singlen* Singlen::getInstance()
{
	return m_pSinglen;
}