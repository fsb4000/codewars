// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

using std::string;

string encrypt(const string& text, int n)
{
	if (n <= 0) {
		return text;
	}

	std::string res;
	res.reserve(text.size());
	for (size_t i{ 1 }; i < text.size(); i += 2) {
		res.push_back(text.at(i));
	}
	for (size_t i{ 0 }; i < text.size(); i += 2) {
		res.push_back(text.at(i));
	}
	return encrypt(res, n-1);
}

string decrypt(const string& encryptedText, int n)
{
	if (n <= 0) {
		return encryptedText;
	}

	std::string res;
	res.reserve(encryptedText.size());
	for (size_t i{ 0 }; i < encryptedText.size(); ++i) {
		if (i % 2 == 1) {
			res.push_back(encryptedText.at(i/2));
		}
		else {
			res.push_back(encryptedText.at(i / 2 + encryptedText.size() / 2));
		}
	}
	return decrypt(res, n - 1);
}