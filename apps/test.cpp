#include <advent/lib.hpp>

#include <string>
#include <cassert>

void test_ssplit_on();

int main() 
{
	test_ssplit_on();
	return 0;
}

void test_ssplit_on() 
{
	std::string s1 = "20-34,15-27";
	std::string s2 = ",";
	auto v1 = ssplit_on(s1, s2);
	assert((v1.front() == std::string("20-34")));
	assert((v1.back() == std::string("15-27")));

	std::string split = "20-34";
	std::string delim = "-";
	auto v2 = ssplit_on(split, delim);
	assert((v2.front() == std::string("20")));
	assert((v2.back() == std::string("34")));
}