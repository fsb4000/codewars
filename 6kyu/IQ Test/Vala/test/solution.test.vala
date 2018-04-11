void addSolutionTests ()
{
    Test.add_func ("/1", _1);
    Test.add_func ("/2", _2);
	Test.add_func ("/3", _3);
	Test.add_func ("/4", _4);
}

void _1()
{
	const int expected = 3;
	int actual = iqTest("2 4 7 8 10");

	assert (expected == actual);
}

void _2()
{
	const int expected = 2;
	int actual = iqTest("1 2 1 1");

	assert (expected == actual);
}

void _3()
{
	const int expected = 4;
	int actual = iqTest("1 1 1 2");

	assert (expected == actual);
}

void _4()
{
	const int expected = 5;
	int actual = iqTest("2 4 8 10 7");

	assert (expected == actual);
}