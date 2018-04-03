function Encrypt ([string]$text, [int]$n)
{
	if ($n -le 0) {
		return $text;
	}

	[string]$res = "";
	for ($i = 1; $i -lt $text.Length; $i += 2) { 
		$res += $text[$i];
	}
	for ($i = 0; $i -lt $text.Length; $i += 2) { 
		$res += $text[$i];
	}

	return encrypt $res ($n-1);
}

function Decrypt ([string]$encryptedText, [int]$n)
{
	if ($n -le 0) {
		return $encryptedText;
	}

	[string]$res = "";
	for ($i = 0 ; $i -lt $encryptedText.Length; $i++) {
		if (($i % 2) -eq 1) {
			$res += $encryptedText[[math]::Truncate($i / 2)];
		}
		else {
			$res += $encryptedText[[math]::Truncate($i / 2) + [math]::Truncate($encryptedText.Length / 2)];
		}
	}
	return decrypt $res ($n - 1);
}

Export-ModuleMember -Function Encrypt;
Export-ModuleMember -Function Decrypt;