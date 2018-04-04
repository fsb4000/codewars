// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

#include <stack>
#include <cctype>

using std::string;
using std::stack;
using std::isdigit;
using std::logic_error;

bool isOperator(char c) noexcept{
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^': return true;
	default: return false;
	}
}

uint8_t getOperatorPriority(char c) {
	switch (c) {
	case '(': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	default: throw logic_error("getOperatorPriority: c is not a operator");
	}
}

bool isLeftAssociativity(char c) noexcept{
	if (c == '^') {
		return false;
	}
	return true;
}

string to_postfix(const string& infix) {
	stack<char> func;
	string res;
	for (const char c : infix) {
		if (isdigit(static_cast<unsigned char>(c))) {
			res += c;
		} 
		else if (c == '(') {
			func.push(c);
		}
		else if (c == ')') {
			while (func.top() != '(') {
				res += func.top();
				func.pop();
			}
			func.pop();
		} 
		else if (isOperator(c)) {
			if (!func.empty()) {
				if (isLeftAssociativity(c)) {
					while (!func.empty() && getOperatorPriority(c) <= getOperatorPriority(func.top())) {
						res += func.top();
						func.pop();
					}
				}
				else {
					while (!func.empty() && getOperatorPriority(c) < getOperatorPriority(func.top())) {
						res += func.top();
						func.pop();
					}
				}
			}
			func.push(c);
		}
	}
	while (!func.empty()) {
		res += func.top();
		func.pop();
	}
	return res;
}