// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.h"

#include <assert.h>
#include <ctype.h>
#include <inttypes.h>
#include <stdbool.h>
#include <string.h>

#include "ut/utarray.h"

static constexpr bool isOperator(char c) noexcept{
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^': return true;
	default: return false;
	}
}

static uint8_t getOperatorPriority(char c) noexcept { // не constexpr, потому что assert не constexpr
	switch (c) {
	case '(': return 0;
	case '-': return 1;
	case '+': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	default: assert(false && "getOperatorPriority: c is not a operator");
	}
	return 4;
}

static constexpr bool isLeftAssociativity(char c) noexcept{
	if (c == '^') {
		return false;
	}

	return true;
}

static const UT_icd ut_char_icd UTARRAY_UNUSED = {sizeof(char),NULL,NULL,NULL};

char* to_postfix(const char* infix) noexcept {
	assert (infix != nullptr);

	const size_t len = strlen(infix);
	size_t res_len = 0;
	char*const res = (char*)malloc(len+1);
	if (res == nullptr) {
		return nullptr;
	}

	UT_array *func;
	utarray_new(func,&ut_char_icd);
	for (size_t i = 0; i < len; ++i) {
		const char c = infix[i];
		if (isdigit((unsigned char)c)) {
			res[res_len] = c;
			++res_len;
		} else if (c == '(') {
			utarray_push_back(func,&c);
		} else if (c == ')') {
			while ((utarray_back(func) != nullptr) && *utarray_back(func) != '(') {
				res[res_len] = *utarray_back(func);
				++res_len;
				utarray_pop_back(func);
			}
			utarray_pop_back(func);
		} else if (isOperator(c)) {
			if (utarray_len(func) != 0) {
				if (isLeftAssociativity(c)) {
					while ((utarray_len(func) != 0) && (getOperatorPriority(c) <= getOperatorPriority(*utarray_back(func)))) {
						res[res_len] = *utarray_back(func);
						++res_len;
						utarray_pop_back(func);
					}
				} else {
					while ((utarray_len(func) != 0) && (getOperatorPriority(c) < getOperatorPriority(*utarray_back(func)))) {
						res[res_len] = *utarray_back(func);
						++res_len;
						utarray_pop_back(func);
					}
				}
			}
			utarray_push_back(func,&c);
		}
	}
	while (utarray_len(func) != 0) {
		res[res_len] = *utarray_back(func);
		++res_len;
		utarray_pop_back(func);
	}
	res[res_len] = '\0';
	utarray_free(func);

	assert(res_len <= len);
	return res;
}