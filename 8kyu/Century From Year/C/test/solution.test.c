// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <unity/unity_fixture.h>

#include "solution.h"
#include <stdio.h>
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
	const int expected = 18;
	const int actual = centuryFromYear(1705);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _2)
{
	const int expected = 19;
	const int actual = centuryFromYear(1900);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _3)
{
	const int expected = 17;
	const int actual = centuryFromYear(1601);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _4)
{
	const int expected = 20;
	const int actual = centuryFromYear(2000);

    TEST_ASSERT_EQUAL (expected, actual);
}

static int modelSolution(int year) noexcept
{
	return (year + 99) / 100;
}

TEST (Solution, _random)
{
	srand ((unsigned int)time(nullptr));
  	for(int i = 0; i < 100; i++)
	{
		const int year = rand()%1000001;
		const int expected = modelSolution(year);
		const int actual = centuryFromYear(year);

		TEST_ASSERT_EQUAL (expected, actual);
  	}
	
}