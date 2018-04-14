using Gee;

uint64 minValue(int[] values)
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
