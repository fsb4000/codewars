function maxTriSum ([int[]]$numbers)
{
  [int[]]$uniqueAndSortedNumbers = [Linq.Enumerable]::Distinct($numbers);
  [int[]]::Sort($uniqueAndSortedNumbers);
  if ($uniqueAndSortedNumbers.Length -ge 3) {
    [int]$len = $uniqueAndSortedNumbers.Length;
    return $uniqueAndSortedNumbers[$len - 1] + $uniqueAndSortedNumbers[$len - 2] + $uniqueAndSortedNumbers[$len - 3];
  }

  return [Linq.Enumerable]::Sum($uniqueAndSortedNumbers);
}

Export-ModuleMember -Function maxTriSum
