void addSolutionTests ()
{
    Test.add_func ("/1", _1);
    Test.add_func ("/2", _2);
    Test.add_func ("/3", _3);
    Test.add_func ("/4", _4);
    Test.add_func ("/5", _5);
    Test.add_func ("/6", _6);
}


void _1()
{
    string expected = "34+";
	string actual = to_postfix("3+4");

    assert (expected == actual);
}

void _2()
{
	string expected = "342*15-2^/+";
	string actual = to_postfix("3+4*2/(1-5)^2");

	assert (expected == actual);
}

void _3()
{
	string expected = "275*+";
	string actual = to_postfix("2+7*5");

	assert (expected == actual);
}

void _4()
{
	string expected = "33*71+/";
	string actual = to_postfix("3*3/(7+1)");

	assert (expected == actual);
}

void _5()
{
	string expected = "562-9*+371-^+";
	string actual = to_postfix("5+(6-2)*9+3^(7-1)");

	assert (expected == actual);
}

void _6()
{
	string expected = "54-1-95/2/+71/7/-";
	string actual = to_postfix("(5-4-1)+9/5/2-7/1/7");

	assert (expected == actual);
}
