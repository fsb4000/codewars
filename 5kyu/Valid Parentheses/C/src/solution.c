// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.h"

#include <assert.h>

bool validParentheses(const char* parens) noexcept
{
	assert(parens != nullptr);
	size_t brackets = 0;
	for (const char* it = parens; *it != '\0'; ++it) {
		const char c = *it;
		if (c == '(') {
			++brackets;
		}
		else if (c == ')') {
			if (brackets == 0) {
				return false;
			}

			--brackets;
		}
	}

	return brackets == 0;
}