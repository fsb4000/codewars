// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

int solve(const std::string& str, int index)
{
	const char openBrace = '(';
	const char closeBrace = ')';
	const int error = -1;
	if (str.at(index) != openBrace) {
		return error;
	}
	int numberOpenBraces = 1;
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
			return i;
		}
	}
	return error;
}