// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

#include <cassert>

using std::string;

static int fact(int n) noexcept
{
	int res = 1;
	for (int i = 1; i <= n; ++i) {
		res *= i;
	}
	return res;
}

string strong_num(const int number)
{
	assert(number > 0);

	int temp = number;
	int res = 0;
	while (temp > 0 && res < number) {
		res += fact(temp % 10);
		temp /= 10;
	}
	if (res == number) {
		return string("STRONG!!!!");
	}

	return string("Not Strong !!");
}
