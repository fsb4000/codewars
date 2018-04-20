// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <unity/unity_fixture.h>

#include "solution.h"

#include <assert.h>
#include <time.h>

TEST_GROUP (Solution);


TEST_SETUP (Solution)
{
}

TEST_TEAR_DOWN (Solution)
{
}


TEST (Solution, _1)
{
	const int expected = 1;
	const int arr[] = {4,6,3};
	const size_t arrLen = sizeof(arr) / sizeof(arr[0]);
	const int actual = minimumSteps(arr, arrLen, 7);

    TEST_ASSERT_EQUAL (expected, actual);
}

/*
static const char* modelSolution(const int number) noexcept
{
	assert(number > 0);

	int temp = number;
	int res = 0;
	while (temp > 0 && res < number) {
		res += fact(temp % 10);
		temp /= 10;
	}
	if (res == number) {
		return "STRONG!!!!";
	}

	return "Not Strong !!";
}
TEST (Solution, _random)
{
	srand ((unsigned int)time(nullptr));
  	for(int i = 0; i < 100; i++)
	{
		const int number = rand()%1000001;
		const char*const expected = modelSolution(number);
		const char*const actual = strong_num(number);

		TEST_ASSERT_EQUAL_STRING (expected, actual);
  	}
	
}
*/