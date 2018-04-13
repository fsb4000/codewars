// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.h"

#include <assert.h>
#include <stdbool.h>

unsigned long long minValue(const int* values, const size_t len) noexcept
{
	bool numbers[10] = {false};
	const size_t numbers_len = sizeof(numbers)/sizeof(numbers[0]);
	for (size_t i = 0; i < len; ++i) {
		const int value = values[i];
		assert(value > 0);
		assert(value < 10);
		numbers[value] = true;
	}
	unsigned long long res = 0;
	for (size_t i = 1; i < numbers_len; ++i) {
		if (numbers[i]) {
			res = res * 10 + i;
		}
	}

	return res;
}
