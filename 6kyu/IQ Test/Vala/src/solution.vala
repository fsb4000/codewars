using Gee;

enum Evenness {Odd, Even}

int iqTest (string str)
{
	int indexOdd = 1;
	int indexEven = 1;
	bool firstEven = true;
	bool firstOdd = true;
	int currentIndex = 1;
	var whatReturn = Evenness.Odd;
	string[] numbers = str.split(" ");
	for (int i = 0; i < numbers.length; ++i, ++currentIndex)
	{
		if (int64.parse(numbers[i]) % 2 == 0) {
			if (firstEven) {
				indexEven = currentIndex;
				firstEven = false;
			}
		}
		else {
			if (firstOdd) {
				indexOdd = currentIndex;
				firstOdd = false;
			}
			else {
				whatReturn = Evenness.Even;
			}
		}
		
	}
	return (whatReturn == Evenness.Even) ? indexEven : indexOdd;
}
