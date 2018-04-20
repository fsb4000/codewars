// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static int compareInts(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}

int minimumSteps(const int* numbers, size_t numbersLen, int input)
{
	assert(numbersLen >= 3);
	for (size_t i = 0; i < numbersLen; ++i) {
		assert(numbers[i] > 0);
	}
	
	int* numbersSorted = (int*)malloc(sizeof(int)*numbersLen);
	assert(numbersSorted != nullptr);
	memcpy(numbersSorted, numbers, numbersLen*sizeof(int));
	qsort(numbersSorted, numbersLen, sizeof(int), compareInts);
	int sum = 0;
	int step = 0;
	for (size_t i = 0; i < numbersLen; ++i) {
		sum += numbersSorted[i];
		if (sum >= input) {
			break;
		}
		++step;
	}
	free(numbersSorted);
	
	return step;
}