#include <advent/lib.hpp>

#include <string>
#include <cassert>

void test_ssplit_on();
void test_grab_and_jump();
void test_grab_and_jump_with_blanks();

int main() 
{
	test_ssplit_on();
	test_grab_and_jump();
	test_grab_and_jump_with_blanks();
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

void test_grab_and_jump()
{
	std::string s("[R] [H] [T] [D] [L] [D] [D] [B] [W]");
	std::istringstream ss(s);

	std::string res = grab_and_jump(ss, 3, 1);
	assert(res == std::string("[R]"));
	res = grab_and_jump(ss, 3, 1);
	assert(res == std::string("[H]"));
}

void test_grab_and_jump_with_blanks()
{
	std::string s("    [M] [G] [W] [S] [F] [G]     [C]");
	std::istringstream ss(s);

	std::string res = grab_and_jump(ss, 3, 1);
	assert(res == std::string("   "));
	res = grab_and_jump(ss, 3, 1);
	assert(res == std::string("[M]"));
}
