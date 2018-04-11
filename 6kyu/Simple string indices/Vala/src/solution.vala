using Gee;

int solve(string str, int index)
{
	const int error = -1;

	if (str.length <= index || str[index] != '(') {
		return error;
	}

	int numberOpenBraces = 1;
	for (int i = index + 1; i < str.length; ++i) {
		switch (str[i]) {
		case '(': 
			++numberOpenBraces;
			break;
		case ')':
			--numberOpenBraces;
			if (numberOpenBraces == 0) {
				return i;
			}
			break;
		default:
			/* do nothing */
			break;
		}
	}

	return error;
}
