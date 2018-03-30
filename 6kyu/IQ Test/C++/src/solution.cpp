#include "solution.hpp"

#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/copy.hpp>


using boost::copy_range;
using boost::is_from_range;
using boost::make_split_iterator;
using boost::token_finder;
using std::stoll;
using std::string;

size_t iqTest(string numbers)
{
	auto index_odd = size_t{ 1 };
	auto index_even = size_t{ 1 };
	auto first_even = true;
	auto first_odd = true;
	auto current_index = size_t{ 1 };
	for (auto it = make_split_iterator(numbers, token_finder(is_from_range(' ', ' ')));
		it != decltype(it)(); ++it, ++current_index)
	{
		if (stoll(copy_range<string>(*it)) % 2 == 0) {
			if (first_even) {
				index_even = current_index;
				first_even = false;
			}
			else if (!first_odd) {
				return index_odd;
			}
		}
		else {
			if (first_odd) {
				index_odd = current_index;
				first_odd = false;
			}
			else if (!first_even) {
				return index_even;
			}
		}
		
	}
	return 1;
}