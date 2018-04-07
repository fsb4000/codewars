// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include <unity/unity_fixture.h>

#include "solution.h"

TEST_GROUP (Solution);


TEST_SETUP (Solution)
{
}

TEST_TEAR_DOWN (Solution)
{
}

TEST (Solution, _1)
{
    const bool expected = true ;
	const bool actual = validParentheses("()");

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _2)
{
    const bool expected = false;
	const bool actual = validParentheses("())");

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _3)
{
    const bool expected = false;
	const bool actual = validParentheses("(");

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _4)
{
    const bool expected = false;
	const bool actual = validParentheses(")(()))");

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _5)
{
    const bool expected = true;
	const bool actual = validParentheses("(())((()())())");

    TEST_ASSERT_EQUAL (expected, actual);
}
