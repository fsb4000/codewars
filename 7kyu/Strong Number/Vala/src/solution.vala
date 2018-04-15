static int fact(int n)
{
	int res = 1;
	for (int i = 1; i <= n; ++i) {
		res *= i;
	}
	return res;
}

unowned string strong_num(int number)
{
	assert(number > 0);

	int temp = number;
	int res = 0;
	while (temp > 0 && res < number) {
		res += fact(temp % 10);
		temp /= 10;
	}
	if (res == number) {
		return "STRONG!!!!";
	}

	return "Not Strong !!";
}