function myAssert ([bool]$condition)
{
    if (-not $condition) {
        throw "assertion failed";
    }
}

function Get-MinValue ([int[]]$values)
{
	[bool[]]$numbers = @($false) * 10;
    foreach ($value in $values) {
        myAssert($value -gt 0);
        myAssert($value -lt 10);
        $numbers[$value] = $true;
    }
    [UInt64]$res = 0;
    for ([int]$i = 1; $i -lt $numbers.Length; ++$i) {
        if ($numbers[$i]) {
            $res = $res * 10 + $i;
        }
    }

    return $res;
}

Export-ModuleMember -Function Get-MinValue