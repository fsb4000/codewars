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
	const unsigned long long expected = 13;
	const int arr[] = { 1,3,1 };
	const size_t len = sizeof(arr)/sizeof(arr[0]);
	const unsigned long long actual = minValue(arr, len);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _2)
{
	const unsigned long long expected = 457;
	const int arr[] = { 4,7,5,7 };
	const size_t len = sizeof(arr)/sizeof(arr[0]);
	const unsigned long long actual = minValue(arr, len);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _3)
{
	const unsigned long long expected = 148;
	const int arr[] = { 4,8,1,4  };
	const size_t len = sizeof(arr)/sizeof(arr[0]);
	const unsigned long long actual = minValue(arr, len);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _4)
{
	const unsigned long long expected = 579;
	const int arr[] = { 5,7,9,5,7  };
	const size_t len = sizeof(arr)/sizeof(arr[0]);
	const unsigned long long actual = minValue(arr, len);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _5)
{
	const unsigned long long expected = 678;
	const int arr[] = { 6,7,8,7,6,6  };
	const size_t len = sizeof(arr)/sizeof(arr[0]);
	const unsigned long long actual = minValue(arr, len);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _6)
{
	const unsigned long long expected = 45679;
	const int arr[] = { 5,6,9,9,7,6,4  };
	const size_t len = sizeof(arr)/sizeof(arr[0]);
	const unsigned long long actual = minValue(arr, len);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _7)
{
	const unsigned long long expected = 134679;
	const int arr[] = { 1,9,1,3,7,4,6,6,7  };
	const size_t len = sizeof(arr)/sizeof(arr[0]);
	const unsigned long long actual = minValue(arr, len);

    TEST_ASSERT_EQUAL (expected, actual);
}

TEST (Solution, _8)
{
	const unsigned long long expected = 356789;
	const int arr[] = { 3,6,5,5,9,8,7,6,3,5,9  };
	const size_t len = sizeof(arr)/sizeof(arr[0]);
	const unsigned long long actual = minValue(arr, len);

    TEST_ASSERT_EQUAL (expected, actual);
}
