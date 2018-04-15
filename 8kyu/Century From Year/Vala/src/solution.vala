using Gee;

int centuryFromYear(int year)
{
	assert(year > 0);
	
	if (year % 100 == 0) {
		return year / 100;
	}

	return year / 100 + 1;
}