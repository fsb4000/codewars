// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

#include <random>

using std::string;

const char*const strong = "STRONG!!!!";
const char*const notStrong = "Not Strong !!";

BOOST_AUTO_TEST_CASE(_1)
{
	const string expected{ strong };
	const string actual{ strong_num(1) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_2)
{
	const string expected{ strong };
	const string actual{ strong_num(2) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_3)
{
	const string expected{ strong };
	const string actual{ strong_num(145) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_4)
{
	const string expected{ notStrong };
	const string actual{ strong_num(7) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_5)
{
	const string expected{ notStrong };
	const string actual{ strong_num(93) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_6)
{
	const string expected{ notStrong };
	const string actual{ strong_num(185) };

	BOOST_CHECK_EQUAL(expected, actual);
}

static int fact(int n) 
{
	int res = 1;
	for (int i = 1; i <= n; ++i) {
		res *= i;
	}
	return res;
}

static string modelSolution(int number) 
{
	assert(number > 0);

	int temp = number;
	int res = 0;
	while (temp > 0 && res < number) {
		res += fact(temp % 10);
		temp /= 10;
	}
	if (res == number) {
		return string("STRONG!!!!");
	}

	return string("Not Strong !!");
}


BOOST_AUTO_TEST_CASE(_random)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> random{ 1, 50000 };
	for (int i{ 0 }; i < 100; ++i)
	{
		const int number = random(gen);
		const string expected{ modelSolution(number) };
		const string actual{ strong_num(number) };

		BOOST_CHECK_EQUAL(expected, actual);
	}
	
}
