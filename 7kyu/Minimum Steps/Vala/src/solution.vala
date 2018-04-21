static int compareInts(void* a, void* b)
{
    int arg1 = *(int*)a;
    int arg2 = *(int*)b;
 
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
 
    // return (arg1 > arg2) - (arg1 < arg2); // possible shortcut
    // return arg1 - arg2; // erroneous shortcut (fails if INT_MIN is present)
}
int minimumSteps(int[] numbers, int input)
{
	assert(numbers.length >= 3);
	for (int i = 0; i < numbers.length; ++i) {
		assert(numbers[i] > 0);
	}
	
	int[] copiedNumbers = numbers;
	Posix.qsort(copiedNumbers, copiedNumbers.length, sizeof(int), compareInts);
	int sum = 0;
	int step = 0;
	for (size_t i = 0; i < copiedNumbers.length; ++i) {
		sum += copiedNumbers[i];
		if (sum >= input) {
			break;
		}
		++step;
	}
	return step;
}
