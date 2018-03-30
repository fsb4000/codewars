// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "solution.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/copy.hpp>

using boost::copy_range;
using boost::is_from_range;
using boost::make_split_iterator;
using boost::token_finder;
using std::stoll;
using std::string_view;
using std::string;

enum class Evenness {Odd, Even};

size_t iqTest(string_view numbers)
{
	auto indexOdd = size_t{ 1 };
	auto indexEven = size_t{ 1 };
	auto firstEven = true;
	auto firstOdd = true;
	auto currentIndex = size_t{ 1 };
	auto whatReturn = Evenness::Odd;
	for (auto it = make_split_iterator(numbers, token_finder(is_from_range(' ', ' ')));
		(it != decltype(it)()); ++it, ++currentIndex)
	{
		if (stoll(copy_range<string>(*it)) % 2 == 0) {
			if (firstEven) {
				indexEven = currentIndex;
				firstEven = false;
			}
		}
		else {
			if (firstOdd) {
				indexOdd = currentIndex;
				firstOdd = false;
			}
			else {
				whatReturn = Evenness::Even;
			}
		}
		
	}
	return (whatReturn == Evenness::Even) ? indexEven : indexOdd;
}