// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

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
		res.emplace_back(m.number, q/m.quantity);
	}
	return min_element(res.begin(), res.end(), [](Multiplier x, Multiplier y) {
		return x.quantity < y.quantity;
	})->quantity;
}

int Zeroes(int base, int number)
{
	return countZeros(number, getMultipliers(base));
}