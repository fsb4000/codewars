// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

#include <algorithm>
#include <numeric>

using namespace std;

int maxTriSum(std::vector<int> numbers)
{
	std::sort(numbers.begin(), numbers.end());
	numbers.erase(std::unique(numbers.begin(), numbers.end()), numbers.end());
	if (numbers.size() >= 3) {
		return numbers.at(numbers.size() - 1) + numbers.at(numbers.size() - 2) + numbers.at(numbers.size() - 3);
	}

	return std::accumulate(numbers.begin(), numbers.end(), 0);
}