void addSolutionTests ()
{
	Test.add_func ("/1", _1);
	Test.add_func ("/2", _2);
	Test.add_func ("/3", _3);
	Test.add_func ("/4", _4);
	Test.add_func ("/5", _5);
	Test.add_func ("/6", _6);
	Test.add_func ("/7", _7);
	Test.add_func ("/8", _8);
	Test.add_func ("/9", _9);
	Test.add_func ("/10", _10);
	Test.add_func ("/11", _11);
	Test.add_func ("/12", _12);
	Test.add_func ("/13", _13);
	Test.add_func ("/14", _14);
}

void _1()
{
	const string expected = "This is a test!";
	string actual = encrypt("This is a test!", -1);

	assert (expected == actual);
}

void _2()
{
	const string expected = "This is a test!";
	string actual = encrypt("This is a test!", 0);

	assert (expected == actual);
}

void _3()
{
	const string expected = "hsi  etTi sats!";
	string actual = encrypt("This is a test!", 1);

	assert (expected == actual);
}

void _4()
{
	const string expected = "s eT ashi tist!";
	string actual = encrypt("This is a test!", 2);

	assert (expected == actual);
}

void _5()
{
	const string expected = " Tah itse sits!";
	string actual = encrypt("This is a test!", 3);

	assert (expected == actual);
}

void _6()
{
	const string expected = "This is a test!";
	string actual = encrypt("This is a test!", 4);

	assert (expected == actual);
}

void _7()
{
	const string expected = "";
	string actual = encrypt("", 3);

	assert (expected == actual);
}

void _8()
{
	const string expected = "This is a test!";
	string actual = decrypt("This is a test!", -1);

	assert (expected == actual);
}

void _9()
{
	const string expected = "This is a test!";
	string actual = decrypt("This is a test!", 0);

	assert (expected == actual);
}

void _10()
{
	const string expected = "This is a test!";
	string actual = decrypt("hsi  etTi sats!", 1);

	assert (expected == actual);
}

void _11()
{
	const string expected = "This is a test!";
	string actual = decrypt("s eT ashi tist!", 2);

	assert (expected == actual);
}

void _12()
{
	const string expected = "This is a test!";
	string actual = decrypt(" Tah itse sits!", 3);

	assert (expected == actual);
}

void _13()
{
	const string expected = "This is a test!";
	string actual = decrypt("This is a test!", 4);

	assert (expected == actual);
}

void _14()
{
	const string expected = "";
	string actual = decrypt("", 3);

	assert (expected == actual);
}
