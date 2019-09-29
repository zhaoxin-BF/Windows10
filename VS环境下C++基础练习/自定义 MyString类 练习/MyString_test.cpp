#include "MyString.hpp"

int str(const char* p)
{
	return strlen(p);
}

int main()
{
	MyString s1;
	MyString s2("s2");
	MyString s2_2 = NULL;
	MyString s3 = s2;
	MyString s4;

	//²âÊÔÔËËã·û·û ºÍ ÖØÔØ[]
	//²âÊÔ = 
	s4 = s2;
	s4 = "s22222222222";

	cout << s4 << endl;
	return 0;
}