// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

using std::string;
using std::size_t;

bool validParentheses(const string& parens) noexcept
{
	auto brackets = size_t{ 0 };
	for (const auto c:  parens) {
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