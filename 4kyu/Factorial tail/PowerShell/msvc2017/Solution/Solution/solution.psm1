function myAssert ([bool]$condition)
{
    if (-not $condition) {
        throw "assertion failed";
    }
}

function Get-CenturyFromYear ([int]$year)
{
	myAssert($year -gt 0);

	if ($year % 100 -eq 0) {
		return [math]::Truncate($year / 100);
	}

	return [math]::Truncate($year / 100) + 1;
}

Export-ModuleMember -Function Get-CenturyFromYear
