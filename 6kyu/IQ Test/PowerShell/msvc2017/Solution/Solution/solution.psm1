Enum Evenness
{
	Odd
	Even
}

function Get-IqTest ([string]$numbers)
{
	[string[]]$separator = [string[]]@(" ")
	[string[]]$array = $numbers.Split($separator, [System.StringSplitOptions]::RemoveEmptyEntries)
	[Int64]$currentIndex = 1
    [bool]$firstEven = $true
    [Int64]$indexEven = 1
    [bool]$firstOdd = $true
    [Int64]$indexOdd = 1
    [Evenness]$whatReturn = [Evenness]::Odd
	
	foreach ($num in $array) { 
        if ([convert]::ToInt64($num,10) % 2 -eq 0) {
            if ($firstEven) {
                $indexEven = $currentIndex
                $firstEven = $false
            }
        } else {
            if ($firstOdd) {
                $indexOdd = $currentIndex
                $firstOdd = $false
            } else {
                $whatReturn = [Evenness]::Even
            }
        }
        $currentIndex++
    }

    if ($whatReturn -eq [Evenness]::Even) {
		return $indexEven
	}
	return $indexOdd
}

Export-ModuleMember -Function Get-IqTest