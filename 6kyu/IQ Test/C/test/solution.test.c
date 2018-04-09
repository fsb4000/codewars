// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <unity/unity_fixture.h>

#include "solution.h"
#include <stdio.h>

TEST_GROUP (Solution);


TEST_SETUP (Solution)
{
}

TEST_TEAR_DOWN (Solution)
{
}

TEST (Solution, _1)
{
	const size_t expected = 3;
	const size_t actual = iqTest("2 4 7 8 10");

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _2)
{
	const size_t expected = 2;
	const size_t actual = iqTest("1 2 1 1");

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _3)
{
	const size_t expected = 4;
	const size_t actual = iqTest("1 1 1 2");

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _4)
{
	const size_t expected = 5;
	const size_t actual = iqTest("2 4 8 10 7");

    TEST_ASSERT_EQUAL (expected, actual);
}

