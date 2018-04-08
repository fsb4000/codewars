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
    const int expected = -1;
	const int actual = solve("0()", 0);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _2)
{
    const int expected = 1;
	const int actual = solve("()", 0);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _3)
{
    const int expected = 10;
	const int actual = solve("((1)23(45))(aB)", 0);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _4)
{
    const int expected = 3;
	const int actual = solve("((1)23(45))(aB)", 1);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _5)
{
    const int expected = -1;
	const int actual = solve("((1)23(45))(aB)", 3);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _6)
{
    const int expected = 9;
	const int actual = solve("((1)23(45))(aB)", 6);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _7)
{
    const int expected = 14;
	const int actual = solve("((1)23(45))(aB)", 11);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _8)
{
    const int expected = 28;
	const int actual = solve("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 11);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _9)
{
    const int expected = -1;
	const int actual = solve("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 28);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _10)
{
    const int expected = 29;
	const int actual = solve("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 0);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _11)
{
    const int expected = 22;
	const int actual = solve("(>_(va)`?(h)C(as)(x(hD)P|(fg)))", 19);

    TEST_ASSERT_EQUAL (expected, actual);
}

