// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

#include <random>

BOOST_AUTO_TEST_CASE(_1)
{
	const int expected{ 17 };
	const int actual{ maxTriSum({ 3,2,6,8,2,3 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_2)
{
	const int expected{ 32 };
	const int actual{ maxTriSum({ 2,9,13,10,5,2,9,5 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_3)
{
	const int expected{ 18 };
	const int actual{ maxTriSum({ 2,1,8,0,6,4,8,6,2,4 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_4)
{
	const int expected{ -9 };
	const int actual{ maxTriSum({ -3,-27,-4,-2,-27,-2 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_5)
{
	const int expected{ -33 };
	const int actual{ maxTriSum({ -14,-12,-7,-42,-809,-14,-12 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_6)
{
	const int expected{ 232 };
	const int actual{ maxTriSum({ -13,-50,57,13,67,-13,57,108,67 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_7)
{
	const int expected{ 41 };
	const int actual{ maxTriSum({ -7,12,-7,29,-5,0,-7,0,0,29 }) };

	BOOST_CHECK_EQUAL(expected, actual);
}

#include <algorithm>
#include <numeric>

using namespace std;

static int modelSolution(std::vector<int> numbers)
{
	std::sort(numbers.begin(), numbers.end());
	numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());
	if (numbers.size() >= 3) {
		return numbers.at(numbers.size() - 1) + numbers.at(numbers.size() - 2) + numbers.at(numbers.size() - 3);
	}

	return std::accumulate(numbers.begin(), numbers.end(), 0);
}


BOOST_AUTO_TEST_CASE(_random)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<std::size_t> randomSize{ 3, 201 };
	std::uniform_int_distribution<> randomElement{ -100, 100 };
	for (int i{ 0 }; i < 100; ++i)
	{
		std::vector<int> numbers(randomSize(gen));
		std::generate(numbers.begin(), numbers.end(), [&]() {return randomElement(gen); });
		const int expected{ modelSolution(numbers) };
		const int actual{ maxTriSum(numbers) };

		BOOST_CHECK_EQUAL(expected, actual);
	}
	
}
