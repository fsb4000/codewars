// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

using std::string;

BOOST_AUTO_TEST_CASE(BasicExample)
{
	const string expected{ "34+" };
	const string actual{ to_postfix("3+4") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(StrongExample)
{
	const string expected{ "342*15-2^/+" };
	const string actual{ to_postfix("3+4*2/(1-5)^2") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(First)
{
	const string expected{ "275*+" };
	const string actual{ to_postfix("2+7*5") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(Second)
{
	const string expected{ "33*71+/" };
	const string actual{ to_postfix("3*3/(7+1)") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(Third)
{
	const string expected{ "562-9*+371-^+" };
	const string actual{ to_postfix("5+(6-2)*9+3^(7-1)") };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(Fourth)
{
	const string expected{ "54-1-95/2/+71/7/-" };
	const string actual{ to_postfix("(5-4-1)+9/5/2-7/1/7") };

	BOOST_CHECK_EQUAL(expected, actual);
}