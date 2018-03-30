// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

BOOST_AUTO_TEST_CASE(Odd)
{
	const size_t expected{ 3 };
	const size_t actual{ iqTest("2 4 7 8 10") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(Even)
{
	const size_t expected{ 2 };
	const size_t actual{ iqTest("1 2 1 1") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(LastEven)
{
	const size_t expected{ 4 }; //-V112
	const size_t actual{ iqTest("1 1 1 2") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(LastOdd)
{
	const size_t expected{ 5 };
	const size_t actual{ iqTest("2 4 8 10 7") };

	BOOST_CHECK_EQUAL(expected, actual);
}