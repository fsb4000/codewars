void addSolutionTests ()
{
	Test.add_func ("/1", _1);
	Test.add_func ("/2", _2);
	Test.add_func ("/3", _3);
	Test.add_func ("/4", _4);
	Test.add_func ("/random", _random);
}

void _1()
{
	const int expected = 18;
	int actual = centuryFromYear(1705);

	assert (expected == actual);
}

void _2()
{
	const int expected = 19;
	int actual = centuryFromYear(1900);

	assert (expected == actual);
}

void _3()
{
	const int expected = 17;
	int actual = centuryFromYear(1601);

	assert (expected == actual);
}

void _4()
{
	const int expected = 20;
	int actual = centuryFromYear(2000);

	assert (expected == actual);
}


static int modelSolution(int year)
{
	return (year + 99) / 100;
}

void _random()
{
	for (int i = 0; i < 100; ++i) {
		int year = Random.int_range (1, 1000001);
		int expected =modelSolution(year);
		int actual = centuryFromYear(year);
        
		assert (expected == actual);
	}
}
