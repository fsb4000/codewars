// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.h"

#include <assert.h>
#include <limits.h>
#include <string.h>

enum braces {
	openBrace = '(',
	closedBrace = ')'
};

int solve(const char* str, size_t index) noexcept
{
	assert (str != nullptr);

	const int error = -1;
	const size_t len = strlen(str);

	if (index > len || str[index] != openBrace) {
		return error;
	}
	
	size_t numberOpenBraces = 1;
	for (size_t i = index + 1ULL; i < len; ++i) {
		switch (str[i]) {
		case openBrace: 
			++numberOpenBraces;
			break;
		case closedBrace:
			--numberOpenBraces;
			if (numberOpenBraces == 0) {
				if (i > (size_t)(INT_MAX)) {
					return error;
				}
				return (int)i;
			}
			break;
		default:
			/* do nothing */
			break;
		}

	}

	return error;
}
