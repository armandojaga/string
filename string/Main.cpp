#include <iostream>

#include "String.h"

String GetMeAString()
{
	return String("another string");
}

int main()
{

	String s1("hello");
	std::cout << "s1:" << s1 << std::endl;

	String s2(s1);
	std::cout << "s1:" << s1 << std::endl;
	std::cout << "s2:" << s2 << std::endl;

	String s3 = std::move(s1);
	std::cout << "s1:" << s1 << std::endl;
	std::cout << "s2:" << s2 << std::endl;
	std::cout << "s3:" << s3 << std::endl;

	String s4;
	s4 = "world";
	std::cout << "s1:" << s1 << std::endl;
	std::cout << "s2:" << s2 << std::endl;
	std::cout << "s3:" << s3 << std::endl;
	std::cout << "s4:" << s4 << std::endl;

	String s5;
	s5 = s4;
	std::cout << "s1:" << s1 << std::endl;
	std::cout << "s2:" << s2 << std::endl;
	std::cout << "s3:" << s3 << std::endl;
	std::cout << "s4:" << s4 << std::endl;
	std::cout << "s5:" << s5 << std::endl;

	s5.clear();
	std::cout << "s5:" << s5 << std::endl;
	std::cout << "s5:" << s5.length() << std::endl;

	String s6 = s3 + s4;
	std::cout << "s1:" << s1 << std::endl;
	std::cout << "s2:" << s2 << std::endl;
	std::cout << "s3:" << s3 << std::endl;
	std::cout << "s4:" << s4 << std::endl;
	std::cout << "s5:" << s5 << std::endl;
	std::cout << "s6:" << s6 << std::endl;

	String s7 = "test";
	std::cout << "s7:" << (s7 == "test") << std::endl;
	std::cout << "Getting a string" << std::endl;

	String s8 = GetMeAString();
	std::cout << "s8:" << s8 << std::endl;
	std::cout << "END" << std::endl;
}
