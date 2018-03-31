// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

#include <gsl-lite.hpp>

#include <limits>

using gsl::narrow;
using std::numeric_limits;

int solve(const std::string& str, size_t index)
{
	const char openBrace = '(';
	const char closeBrace = ')';
	const int error = -1;
	if (str.at(index) != openBrace) {
		return error;
	}
	size_t numberOpenBraces = 1;
	for (size_t i = index + 1ULL; i < str.size(); ++i) {
		switch (str.at(i)) {
		case openBrace: 
			++numberOpenBraces;
			break;
		case closeBrace:
			--numberOpenBraces;
			break;
		default:
			/* do nothing */
			break;
		}
		if (numberOpenBraces == 0) {
			if (i > narrow<size_t>(numeric_limits<int>::max())) {
				return error;
			}
			return narrow<int>(i);
		}
	}
	return error;
}