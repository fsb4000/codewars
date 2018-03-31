<#
.SYNOPSIS
In this Kata, you will be given a string with brackets and an index of an opening bracket and 
your task will be to return the index of the matching closing bracket. 
An opening brace will always have a closing brace. Return -1 if there is no answer
#>
function Get-Solution ([string]$str, [int]$index)
{
	Set-Variable -name openBrace -value ([char]'(') -option Constant
	Set-Variable -name closeBrace -value ([char]')') -option Constant
	Set-Variable -name error -value ([int]-1) -option Constant

	if ($str[$index] -ne $openBrace) {
		return $error
	}

	[int]$numberOpenBraces = 1;
	for ([int]$i = $index + 1; $i -lt $str.Length; ++$i) {
		switch ($str[$i]) {
		$openBrace {
				++$numberOpenBraces;
				break;
			}
		$closeBrace {
				--$numberOpenBraces;
				break;
			}
		Default {
				# do nothing 
				break;
			}
		}

		if ($numberOpenBraces -eq 0) {
			return $i
		}
	}
	return $error;
}

Export-ModuleMember -Function Get-Solution