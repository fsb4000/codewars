// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

#include <algorithm>
#include <cassert>
#include <array>

using std::vector;
using std::array;

unsigned long long minValue(const vector<int>& values) noexcept
{
	auto numbers = std::array<bool, 10>{};
	for (const auto value : values) {
		assert(value > 0);
		assert(value < 10);
		numbers.at(value) = true;
	}
	auto res = unsigned long long{};
	for (auto i = size_t{ 1 }; i < numbers.size(); ++i) {
		if (numbers.at(i)) {
			res = res * 10 + i;
		}
	}

	return res;
}
