// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

BOOST_AUTO_TEST_CASE(FirstExample)
{
	const int expected{ 10 };
	const int actual{ solve("((1)23(45))(aB)", 0) };

	BOOST_CHECK_EQUAL(expected, actual);
}
