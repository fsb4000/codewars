// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#define BOOST_TEST_MODULE Solution
#include <boost/test/unit_test.hpp>

#include "solution.hpp"

using std::string;

BOOST_AUTO_TEST_CASE(EncryptTestsNegative)
{
	const string expected{ "This is a test!" };
	const string actual{ encrypt("This is a test!", -1) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(EncryptTests0)
{
	const string expected{ "This is a test!" };
	const string actual{ encrypt("This is a test!", 0) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(EncryptTests1)
{
	const string expected{ "hsi  etTi sats!" };
	const string actual{ encrypt("This is a test!", 1) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(EncryptTests2)
{
	const string expected{ "s eT ashi tist!" };
	const string actual{ encrypt("This is a test!", 2) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(EncryptTests3)
{
	const string expected{ " Tah itse sits!" };
	const string actual{ encrypt("This is a test!", 3) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(EncryptTests4)
{
	const string expected{ "This is a test!" };
	const string actual{ encrypt("This is a test!", 4) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(EncryptTests5)
{
	const string expected{ };
	const string actual{ encrypt("", 3) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(DecryptTestsNegative)
{
	const string expected{ "This is a test!" };
	const string actual{ decrypt("This is a test!", -1) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(DecryptTests0)
{
	const string expected{ "This is a test!" };
	const string actual{ decrypt("This is a test!", 0) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(DecryptTests1)
{
	const string expected{ "This is a test!" };
	const string actual{ decrypt("hsi  etTi sats!", 1) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(DecryptTests2)
{
	const string expected{ "This is a test!" };
	const string actual{ decrypt("s eT ashi tist!", 2) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(DecryptTests3)
{
	const string expected{ "This is a test!" };
	const string actual{ decrypt(" Tah itse sits!", 3) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(DecryptTests4)
{
	const string expected{ "This is a test!" };
	const string actual{ decrypt("This is a test!", 4) };

	BOOST_CHECK_EQUAL(expected, actual);
}

BOOST_AUTO_TEST_CASE(DecryptTests5)
{
	const string expected{ };
	const string actual{ decrypt("", 3) };

	BOOST_CHECK_EQUAL(expected, actual);
}
