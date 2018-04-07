// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <unity/unity_fixture.h>

#include "solution.h"
#include <stdio.h>

TEST_GROUP (Solution);

char* actual = nullptr;

TEST_SETUP (Solution)
{
    actual = nullptr;
}

TEST_TEAR_DOWN (Solution)
{
    free(actual);
}

TEST (Solution, _1)
{
    const char* expected = "34+";
    actual = to_postfix("3+4");

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _2)
{
    const char* expected = "342*15-2^/+";
    actual = to_postfix("3+4*2/(1-5)^2");

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _3)
{
    const char* expected = "275*+";
    actual = to_postfix("2+7*5");

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _4)
{
	const char* expected =  "33*71+/";
	actual = to_postfix("3*3/(7+1)");

	TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _5)
{
    const char* expected =  "562-9*+371-^+";
	actual = to_postfix("5+(6-2)*9+3^(7-1)");

	TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _6)
{
    const char* expected =  "54-1-95/2/+71/7/-";
	actual = to_postfix("(5-4-1)+9/5/2-7/1/7");

	TEST_ASSERT_EQUAL_STRING (expected, actual);
}
