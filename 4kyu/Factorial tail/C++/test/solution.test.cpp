// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

#include <random>

BOOST_AUTO_TEST_CASE(_1)
{
	const int expected = 2;
	const int actual{ Zeroes(10, 10) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_2)
{
	const int expected = 3;
	const int actual{ Zeroes(16, 16) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_3)
{
	const int expected = 0;
	const int actual{ Zeroes(5, 3) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_4)
{
	const int expected = 1;
	const int actual{ Zeroes(66, 14) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(_5)
{
	const int expected = 2;
	const int actual{ Zeroes(36, 12) };

	BOOST_CHECK_EQUAL(expected, actual);
}

#include <cassert>
#include <vector>
#include <algorithm>
#include <iostream>

using std::vector;
namespace {
	struct Multiplier
	{
		int number;
		int quantity;

		Multiplier(int n = 0, int q = 0)
			: number(n)
			, quantity(q)
		{}
	};
}

static bool isPrime(int n)
{
	assert(n >= 1);
	if (n == 1)
	{
		return false;
	}
	if (n == 2)
	{
		return true;
	}
	if (n % 2 == 0)
	{
		return false;
	}
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

static vector<int> getPrimes(int max) {
	vector<int> res;
	for (int i = 2; i <= max; ++i) {
		if (isPrime(i)) {
			res.push_back(i);
		}
	}
	return res;
}

static vector<Multiplier> getMultipliers(int n) {
	vector<int> primes = getPrimes(n);
	vector<Multiplier> res;
	for (auto prime : primes) {
		int temp = n;
		int q = 0;
		while (temp % prime == 0) {
			++q;
			temp /= prime;
		}
		if (q != 0) {
			res.emplace_back(prime, q);
		}
	}
	return res;
}

static int countZeros(int n, const vector<Multiplier>& multipliers) {
	vector<Multiplier> res;
	for (auto m : multipliers) {
		int multiplier = m.number;
		int q = 0;
		while (n / multiplier > 0) {
			q += n / multiplier;
			multiplier *= m.number;
		}
		res.emplace_back(m.number, q / m.quantity);
	}
	return min_element(res.begin(), res.end(), [](Multiplier x, Multiplier y) {
		return x.quantity < y.quantity;
	})->quantity;
}

static int modelSolution(int base, int number)
{
	return countZeros(number, getMultipliers(base));
}

BOOST_AUTO_TEST_CASE(_random)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> randomBase{ 2, 256 };
	std::uniform_int_distribution<> randomNumber{ 1, 100000 };
	for (int i{ 0 }; i < 100; ++i)
	{
		const int base = randomBase(gen);
		const int number = randomNumber(gen);
		const int expected{ modelSolution(base, number) };
		const int actual{ Zeroes(base, number) };
		BOOST_CHECK_EQUAL(expected, actual);
	}
	
}
