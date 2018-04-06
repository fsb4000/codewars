// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"


BOOST_AUTO_TEST_CASE(_1)
{
	const bool expected{ true };
	const bool actual{ validParentheses("()") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_2)
{
	const bool expected{ false };
	const bool actual{ validParentheses("())") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_3)
{
	const bool expected{ false };
	const bool actual{ validParentheses("(") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_4)
{
	const bool expected{ false };
	const bool actual{ validParentheses(")(()))") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_5)
{
	const bool expected{ true };
	const bool actual{ validParentheses("(())((()())())") };

	BOOST_CHECK_EQUAL(expected, actual);
}