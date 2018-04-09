bool validParentheses(string parens)
{
	size_t brackets = 0;
	for (int i = 0; i < parens.length; ++i) {
		char c = parens[i];
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
