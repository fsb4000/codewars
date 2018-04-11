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
}


void _1()
{
    const int expected = -1;
	int actual = solve("0()", 0);

    assert (expected == actual);
}

void _2()
{
    const int expected = 1;
	int actual = solve("()", 0);

    assert (expected == actual);
}

void _3()
{
    const int expected = 10;
	int actual = solve("((1)23(45))(aB)", 0);

    assert (expected == actual);
}

void _4()
{
    const int expected = 3;
	int actual = solve("((1)23(45))(aB)", 1);

    assert (expected == actual);
}

void _5()
{
	const int expected = -1;
	int actual = solve("((1)23(45))(aB)", 3);

	assert (expected == actual);
}

void _6()
{
	const int expected = 9;
	int actual = solve("((1)23(45))(aB)", 6);

	assert (expected == actual);
}

void _7()
{
	const int expected = 14;
	int actual = solve("((1)23(45))(aB)", 11);

	assert (expected == actual);
}

void _8()
{
	const int expected = 28;
	int actual = solve("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 11);

	assert (expected == actual);
}

void _9()
{
	const int expected = -1;
	int actual = solve("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 28);

	assert (expected == actual);
}

void _10()
{
	const int expected = 29;
	int actual = solve("(g(At)IO(f)(tM(qk)YF(n)Nr(E)))", 0);

	assert (expected == actual);
}

void _11()
{
	const int expected = 22;
	int actual = solve("(>_(va)`?(h)C(as)(x(hD)P|(fg)))", 19);

	assert (expected == actual);
}
