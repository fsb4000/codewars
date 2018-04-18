// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

#include <random>

BOOST_AUTO_TEST_CASE(_1)
{
	const int expected{ 1 };
	const int actual{ minimumSteps({ 4,6,3 }, 7) };

	BOOST_CHECK_EQUAL(expected, actual);
}
/*
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
*/