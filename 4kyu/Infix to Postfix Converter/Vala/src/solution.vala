using Gee;

bool isOperator(char c) {
	switch (c) {
	case '+':
	case '-':
	case '*':
	case '/':
	case '^': return true;
	default: return false;
	}
}

uint8 getOperatorPriority(char c) {
	switch (c) {
	case '(': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	default: 
		assert(false);
		break;
	}
	return 4;
}

bool isLeftAssociativity(char c) {
	if (c == '^') {
		return false;
	}

	return true;
}

string to_postfix(string infix) {
	var func = new ArrayList<char>();
	var res = new StringBuilder.sized(infix.length);
	bool successful = true;
	for (int i = 0; i < infix.length; ++i) {
		char c = infix[i];
		if (c.isdigit()) {
			res.append_c(c);
		} else if (c == '(') {
			successful = func.add(c);
			assert (successful);
		} else if (c == ')') {
			while (func[func.size - 1] != '(') {
				res.append_c(func[func.size - 1]);
				func.remove_at(func.size - 1);
			}
			func.remove_at(func.size - 1);
		} else if (isOperator(c)) {
			if (func.size > 0) {
				if (isLeftAssociativity(c)) {
					while (func.size > 0 && getOperatorPriority(c) <= getOperatorPriority(func[func.size - 1])) {
						res.append_c(func[func.size - 1]);
						func.remove_at(func.size - 1);
					}
				} else {
					while (func.size > 0 && getOperatorPriority(c) < getOperatorPriority(func[func.size - 1])) {
						res.append_c(func[func.size - 1]);
						func.remove_at(func.size - 1);
					}
				}
			}
			successful = func.add(c);
			assert (successful);
		}
	}
	while (func.size > 0) {
		res.append_c(func[func.size - 1]);
		func.remove_at(func.size - 1);
	}

	return res.str;
}
