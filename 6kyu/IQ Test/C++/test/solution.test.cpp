#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

BOOST_AUTO_TEST_CASE(Odd)
{
	int32_t expected = 3;
	int32_t actual = iqTest("2 4 7 8 10");

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(Even)
{
	int32_t expected = 2;
	int32_t actual = iqTest("1 2 1 1");

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(LastEven)
{
	int32_t expected = 4;
	int32_t actual = iqTest("1 1 1 2");

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(LastOdd)
{
	int32_t expected = 5;
	int32_t actual = iqTest("2 4 8 10 7");

	BOOST_CHECK_EQUAL(expected, actual);
}