void addSolutionTests ()
{
	Test.add_func ("/1", _1);
	Test.add_func ("/2", _2);
	Test.add_func ("/3", _3);
	Test.add_func ("/4", _4);
	Test.add_func ("/5", _5);
	Test.add_func ("/6", _6);
	Test.add_func ("/random", _random);
}

const string strong = "STRONG!!!!";
const string notStrong = "Not Strong !!";

void _1()
{
	const string expected = strong;
	unowned string actual = strong_num(1);

	assert (expected == actual);
}

void _2()
{
	const string expected = strong;
	unowned string actual = strong_num(2);

	assert (expected == actual);
}

void _3()
{
	const string expected = strong;
	unowned string actual = strong_num(145);

	assert (expected == actual);
}

void _4()
{
	const string expected = notStrong;
	unowned string actual = strong_num(7);

	assert (expected == actual);
}

void _5()
{
	const string expected = notStrong;
	unowned string actual = strong_num(93);

	assert (expected == actual);
}

void _6()
{
	const string expected = notStrong;
	unowned string actual = strong_num(185);

	assert (expected == actual);
}

static int modelSolutionFact(int n)
{
	int res = 1;
	for (int i = 1; i <= n; ++i) {
		res *= i;
	}
	return res;
}

static unowned string modelSolution(int number)
{
	assert(number > 0);

	int temp = number;
	int res = 0;
	while (temp > 0 && res < number) {
		res += modelSolutionFact(temp % 10);
		temp /= 10;
	}
	if (res == number) {
		return "STRONG!!!!";
	}

	return "Not Strong !!";
}

void _random()
{
	for (int i = 0; i < 100; ++i) {
		int number = Random.int_range (1, 1000001);
		unowned string expected =modelSolution(number);
		unowned string actual = strong_num(number);
        
		assert (expected == actual);
	}
}
