// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.h"

#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

char* encrypt(const char* text, int n) noexcept
{
	assert (text != nullptr);

	if (n <= 0) {
		return strdup(text);
	}

	const size_t len = strlen(text);
	char* temp = (char*)malloc(len+1);
	assert (temp != nullptr);
	size_t current = 0;
	for (size_t i =1; i < len; i += 2) {
		temp[current] = text[i];
		++current;
	}
	for (size_t i = 0; i < len; i += 2) {
		temp[current] = text[i];
		++current;
	}
	temp[current] = '\0';
	assert(current == len);
	char* res = encrypt(temp, n-1);
	free(temp);

	return res;
}

char* decrypt(const char* encryptedText, int n) noexcept
{
	assert (encryptedText != nullptr);

	if (n <= 0) {
		return strdup(encryptedText);
	}

	const size_t len = strlen(encryptedText);
	char* temp = (char*)malloc(len+1);
	assert (temp != nullptr);
	size_t current = 0;
	for (size_t i = 0; i < len; ++i) {
		if (i % 2 == 1) {
			temp[current] = encryptedText[i/2];
		}
		else {
			temp[current] = encryptedText[i / 2 + len / 2];
		}
		++current;
	}
	temp[current] = '\0';
	assert(current == len);
	char* res = decrypt(temp, n-1);
	free(temp);

	return res;
}
