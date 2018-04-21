void addSolutionTests ()
{
	Test.add_func ("/1", _1);
}

void _1()
{
	const int expected = 1;
	int actual = minimumSteps({ 4,6,3 }, 7);

	assert (expected == actual);
}


/* 

void _random()
{
	for (int i = 0; i < 100; ++i) {
		int number = Random.int_range (1, 1000001);
		unowned string expected =modelSolution(number);
		unowned string actual = strong_num(number);
        
		assert (expected == actual);
	}
}
*/
