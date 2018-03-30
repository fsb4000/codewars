// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

BOOST_AUTO_TEST_CASE(NoBrace)
{
	const int expected{ -1 };
	const int actual{ solve("0()", 0) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(BasicExample)
{
	const int expected{ 1 };
	const int actual{ solve("()", 0) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(FirstExample)
{
	const int expected{ 10 };
	const int actual{ solve("((1)23(45))(aB)", 0) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(SecondExample)
{
	const int expected{ 3 };
	const int actual{ solve("((1)23(45))(aB)", 1) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(ThirdExample)
{
	const int expected{ -1 };
	const int actual{ solve("((1)23(45))(aB)", 3) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(FourthExample)
{
	const int expected{ 9 };
	const int actual{ solve("((1)23(45))(aB)", 6) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(FifthExample)
{
	const int expected{ 14 };
	const int actual{ solve("((1)23(45))(aB)", 11) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(SixthExample)
{
	const int expected{ 28 };
	const int actual{ solve("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 11) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(SeventhExample)
{
	const int expected{ -1 };
	const int actual{ solve("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 28) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(EightthExample)
{
	const int expected{ 29 };
	const int actual{ solve("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 0) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(NinethExample)
{
	const int expected{ 22 };
	const int actual{ solve("(>_(va)`?(h)C(as)(x(hD)P|(fg)))", 19) };

	BOOST_CHECK_EQUAL(expected, actual);
}
