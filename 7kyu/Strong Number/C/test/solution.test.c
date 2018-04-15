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

const char*const strong = "STRONG!!!!";
const char*const notStrong = "Not Strong !!";

TEST (Solution, _1)
{
	const char*const expected = strong;
	const char*const actual = strong_num(1);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _2)
{
	const char*const expected = strong;
	const char*const actual = strong_num(2);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _3)
{
	const char*const expected = strong;
	const char*const actual = strong_num(145);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _4)
{
	const char*const expected = notStrong;
	const char*const actual = strong_num(7);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _5)
{
	const char*const expected = notStrong;
	const char*const actual = strong_num(93);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _6)
{
	const char*const expected = notStrong;
	const char*const actual = strong_num(185);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

static int fact(int n) noexcept
{
	int res = 1;
	for (int i = 1; i <= n; ++i) {
		res *= i;
	}
	return res;
}

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