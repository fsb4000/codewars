// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

#include <algorithm>
#include <cassert>
#include <functional>
#include <queue>


using std::vector;
using std::sort;
using std::greater;

int minimumSteps(const std::vector <int>& numbers, int input)
{
	assert(numbers.size() >= 3);
	for (auto n : numbers) {
		assert(n > 0);
	}
	
	std::priority_queue<int, std::vector<int>, std::greater<int> > q;
	for (auto n : numbers) {
		q.push(n);
	}

	int sum = 0;
	int step = 0;
	while (sum < input && q.size() >= 2) {
		const auto smallest = q.top(); q.pop();
		sum += smallest;
		++step;
	}

	return step;
}
