function Encrypt ([string]$text, [int]$n)
{
	if ($n -le 0) {
		return $text;
	}

	[Text.StringBuilder]$res = New-Object -TypeName "System.Text.StringBuilder";
	$res.Capacity = $text.Length;
	for ($i = 1; $i -lt $text.Length; $i += 2) { 
		[void]$res.Append($text[$i]);
	}
	for ($i = 0; $i -lt $text.Length; $i += 2) { 
		[void]$res.Append($text[$i]);
	}

	return encrypt $res.ToString() ($n-1);
}

function Decrypt ([string]$encryptedText, [int]$n)
{
	if ($n -le 0) {
		return $encryptedText;
	}

	[Text.StringBuilder]$res = New-Object -TypeName "System.Text.StringBuilder";
	$res.Capacity = $encryptedText.Length;
	for ($i = 0 ; $i -lt $encryptedText.Length; $i++) {
		if (($i % 2) -eq 1) {
			[void]$res.Append($encryptedText[[math]::Truncate($i / 2)]);
		}
		else {
			[void]$res.Append($encryptedText[[math]::Truncate($i / 2) + [math]::Truncate($encryptedText.Length / 2)]);
		}
	}
	return decrypt $res.ToString() ($n - 1);
}

Export-ModuleMember -Function Encrypt;
Export-ModuleMember -Function Decrypt;