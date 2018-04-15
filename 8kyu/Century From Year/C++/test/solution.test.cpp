// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

#include <random>

BOOST_AUTO_TEST_CASE(_1)
{
	const int expected{ 18 };
	const int actual{ centuryFromYear(1705) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_2)
{
	const int expected{ 19 };
	const int actual{ centuryFromYear(1900) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_3)
{
	const int expected{ 17 };
	const int actual{ centuryFromYear(1601) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_4)
{
	const int expected{ 20 };
	const int actual{ centuryFromYear(2000) };

	BOOST_CHECK_EQUAL(expected, actual);
}

static int modelSolution(int year) noexcept
{
	return (year + 99) / 100;
}

BOOST_AUTO_TEST_CASE(_random)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> random{ 1, 1000000 };
	for (int i{ 0 }; i < 100; ++i)
	{
		const int year = random(gen);
		const int expected{ modelSolution(year) };
		const int actual{ centuryFromYear(year) };

		BOOST_CHECK_EQUAL(expected, actual);
	}
	
}
