// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

#include <cassert>

int centuryFromYear(int year) noexcept
{
	assert(year > 0);
	
	if (year % 100 == 0) {
		return year / 100;
	}

	return year / 100 + 1;
}
