// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

BOOST_AUTO_TEST_CASE(_1)
{
	const unsigned long long expected{ 13 };
	const unsigned long long actual{ minValue({ 1,3,1 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_2)
{
	const unsigned long long expected{ 457 };
	const unsigned long long actual{ minValue({ 4,7,5,7 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_3)
{
	const unsigned long long expected{ 148 };
	const unsigned long long actual{ minValue({ 4,8,1,4 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_4)
{
	const unsigned long long expected{ 579 };
	const unsigned long long actual{ minValue({ 5,7,9,5,7 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_5)
{
	const unsigned long long expected{ 678 };
	const unsigned long long actual{ minValue({ 6,7,8,7,6,6 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_6)
{
	const unsigned long long expected{ 45679 };
	const unsigned long long actual{ minValue({ 5,6,9,9,7,6,4 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_7)
{
	const unsigned long long expected{ 134679 };
	const unsigned long long actual{ minValue({ 1,9,1,3,7,4,6,6,7 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_8)
{
	const unsigned long long expected{ 356789 };
	const unsigned long long actual{ minValue({ 3,6,5,5,9,8,7,6,3,5,9 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}
