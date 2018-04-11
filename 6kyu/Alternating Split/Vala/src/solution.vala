using Gee;

string encrypt(string text, int n)
{
	if (n <= 0) {
		return text;
	}

	var res = new StringBuilder.sized(text.length);
	for (int i = 1; i < text.length; i += 2) {
		res.append_c(text[i]);
	}
	for (int i = 0; i < text.length; i += 2) {
		res.append_c(text[i]);
	}
	return encrypt(res.str, n-1);
}

string decrypt(string encryptedText, int n)
{
	if (n <= 0) {
		return encryptedText;
	}

	var res = new StringBuilder.sized(encryptedText.length);
	for (int i = 0; i < encryptedText.length; ++i) {
		if (i % 2 == 1) {
			res.append_c(encryptedText[i/2]);
		}
		else {
			res.append_c(encryptedText[i / 2 + encryptedText.length / 2]);
		}
	}
	return decrypt(res.str, n - 1);
}