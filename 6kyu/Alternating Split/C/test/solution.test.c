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
	const char* expected = "This is a test!";
	actual = encrypt("This is a test!", -1);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _2)
{
	const char* expected = "This is a test!";
	actual = encrypt("This is a test!", 0);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _3)
{
	const char* expected = "hsi  etTi sats!";
	actual = encrypt("This is a test!", 1);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _4)
{
	const char* expected = "s eT ashi tist!";
	actual = encrypt("This is a test!", 2);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _5)
{
	const char* expected = " Tah itse sits!";
	actual = encrypt("This is a test!", 3);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _6)
{
	const char* expected = "This is a test!";
	actual = encrypt("This is a test!", 4);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _7)
{
	const char* expected = "";
	actual = encrypt("", 3);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _8)
{
	const char* expected = "This is a test!";
	actual = decrypt("This is a test!", -1);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _9)
{
	const char* expected = "This is a test!";
	actual = decrypt("This is a test!", 0);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _10)
{
	const char* expected = "This is a test!";
	actual = decrypt("hsi  etTi sats!", 1);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _11)
{
	const char* expected = "This is a test!";
	actual = decrypt("s eT ashi tist!", 2);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _12)
{
	const char* expected = "This is a test!";
	actual = decrypt(" Tah itse sits!", 3);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _13)
{
	const char* expected = "This is a test!";
	actual = decrypt("This is a test!", 4);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}

TEST (Solution, _14)
{
	const char* expected = "";
	actual = decrypt("", 3);

    TEST_ASSERT_EQUAL_STRING (expected, actual);
}
