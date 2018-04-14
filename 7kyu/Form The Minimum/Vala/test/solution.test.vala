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
	Test.add_func ("/random", _random);
}

uint64 modelSolution(int[] values)
{
	var numbers = new bool[10];
    foreach (var value in values) {
        assert (value > 0);
        assert (value < 10);
        numbers[value] = true;
    }
    uint64 res = 0;
    for (int i = 1; i < numbers.length; ++i) {
        if (numbers[i]) {
            res = res * 10 + i;
        }
    }

    return res;
}

void _1()
{
	const uint64 expected = 13;
	uint64 actual = minValue({1, 3, 1});

	assert (expected == actual);
}

void _2()
{
	const uint64 expected = 457;
	uint64 actual = minValue({4, 7, 5, 7});

	assert (expected == actual);
}

void _3()
{
	const uint64 expected = 148;
	uint64 actual = minValue({4, 8, 1, 4});

	assert (expected == actual);
}

void _4()
{
	const uint64 expected = 579;
	uint64 actual = minValue({5, 7, 9, 5, 7});

	assert (expected == actual);
}

void _5()
{
	const uint64 expected = 678;
	uint64 actual = minValue({6, 7, 8, 7, 6, 6});

	assert (expected == actual);
}

void _6()
{
	const uint64 expected = 45679;
	uint64 actual = minValue({5, 6, 9, 9, 7, 6, 4});

	assert (expected == actual);
}

void _7()
{
	const uint64 expected = 134679;
	uint64 actual = minValue({1, 9, 1, 3, 7, 4, 6, 6, 7});

	assert (expected == actual);
}

void _8()
{
	const uint64 expected = 356789;
	uint64 actual = minValue({3, 6, 5, 5, 9, 8, 7, 6, 3, 5, 9});

	assert (expected == actual);
}

void _random()
{
	for (int i = 0; i < 100; ++i) {
		int randomTestInputSize = Random.int_range (3, 16); // Vector size range: [3, 16)
		var random_input = new int[randomTestInputSize];
            
		for(int j = 0; j < random_input.length; ++j) {
			random_input[j] =  Random.int_range (1, 10); // Element value range: [1, 10)
		}
		uint64 expected =modelSolution(random_input);
		uint64 actual = minValue(random_input);
        
		assert (expected == actual);
	}
}
