// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.h"

#include <assert.h>

static int fact(int n) noexcept
{
	int res = 1;
	for (int i = 1; i <= n; ++i) {
		res *= i;
	}
	return res;
}

const char* strong_num(const int number) noexcept
{
	assert(number > 0);

	int temp = number;
	int res = 0;
	while (temp > 0 && res < number) {
		res += fact(temp % 10);
		temp /= 10;
	}
	if (res == number) {
		return "STRONG!!!!";
	}

	return "Not Strong !!";
}
