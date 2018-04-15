function myAssert ([bool]$condition)
{
  if (-not $condition) {
    throw "assertion failed";
  }
}

function fact ([int]$n)
{
  [int]$res = 1;
  for ([int]$i = 1; $i -le $n;++ $i) {
    $res *= $i;
  }

  return $res;
}

function strongNumber ([int]$number)
{
  myAssert ($number -gt 0);

  [int]$temp = $number;
  [int]$res = 0;
  while (($temp -gt 0) -and ($res -lt $number)) {
    $res += fact ($temp % 10);
    $temp /= 10;
  }
  if ($res -eq $number) {
    return "STRONG!!!!";
  }

  return "Not Strong !!";
}

Export-ModuleMember -Function strongNumber
