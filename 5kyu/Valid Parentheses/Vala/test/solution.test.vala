void addSolutionTests ()
{
    Test.add_func ("/1", _1);
    Test.add_func ("/2", _2);
    Test.add_func ("/3", _3);
    Test.add_func ("/4", _4);
    Test.add_func ("/5", _5);
}


void _1()
{
    bool expected = true;
	bool actual = validParentheses("()");

    assert (expected == actual);
}

void _2()
{
    bool expected = false;
	bool actual = validParentheses("())");

    assert (expected == actual);
}

void _3()
{
    bool expected = false;
	bool actual = validParentheses("(");

    assert (expected == actual);
}

void _4()
{
    bool expected = false;
	bool actual = validParentheses(")(()))");

    assert (expected == actual);
}

void _5()
{
    bool expected = true;
	bool actual = validParentheses("(())((()())())");

    assert (expected == actual);
}
