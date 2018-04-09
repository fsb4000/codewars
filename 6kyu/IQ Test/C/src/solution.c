// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.h"

#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>

enum Evenness {Odd, Even};

size_t iqTest(const char* numbers) noexcept
{
	assert (numbers != nullptr);

	size_t indexOdd = 1;
	size_t indexEven = 1;
	bool firstEven = true;
	bool firstOdd = true;
	size_t currentIndex = 1;
	enum Evenness whatReturn = Odd;
	char* input = strdup(numbers);
    for (char* token = strtok(input, " ");token != nullptr;token = strtok(NULL, " "), ++currentIndex) {
      if (atoll(token) % 2 == 0) {
			if (firstEven) {
				indexEven = currentIndex;
				firstEven = false;
			}
		}
		else {
			if (firstOdd) {
				indexOdd = currentIndex;
				firstOdd = false;
			} else {
				whatReturn = Even;
			}
		}
		
	}
	free(input);
	return (whatReturn == Even) ? indexEven : indexOdd;
}
