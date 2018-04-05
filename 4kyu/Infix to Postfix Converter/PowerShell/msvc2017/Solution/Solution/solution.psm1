function isOperator ([char]$maybeOp)
{
	switch ($maybeOp) {
        '+' {return $true;}
        '-' {return $true;}
        '*' {return $true;}
        '/' {return $true;}
        '^' {return $true;}
        default {return $false;}
    }
}

function isLeftAssociativity ([char]$op) {
    if ($op -eq '^') {
        return $false;
    }

    return $true;
}

function getOperatorPriority ([char]$op) {
    switch ($op) {
        '(' {return 0;}
        '+' {return 1;}
        '-' {return 1;}
        '*' {return 2;}
        '/' {return 2;}
        '^' {return 3;}
        default { throw "getOperatorPriority: op is not a operator";}
    }
};

function toPostfix ([string]$infix)
{
	[Collections.Generic.Stack[char]]$func =New-Object -TypeName "System.Collections.Generic.Stack[char]";
	[Text.StringBuilder]$res = New-Object -TypeName "System.Text.StringBuilder";
	foreach ($c in [char[]]$infix) {
		if ([char]::IsNumber($c)) {
			[void]$res.Append($c);
		} elseif ($c -eq '(') {
			$func.Push($c);
		} elseif ($c -eq ')') {
            while ($func.Peek() -ne '(') {
                [void]$res.Append($func.Pop());
            }
            [void]$func.Pop();
        } elseif (isOperator($c)) {
            if ($func.Count -ne 0) {
                if (isLeftAssociativity($c)) {
                    while ( ($func.Count -ne 0) -and ((getOperatorPriority($c)) -le (getOperatorPriority($func.Peek())))) {
                        [void]$res.Append($func.Pop());
                    }
                } else {
                    while (($func.Count -ne 0) -and ((getOperatorPriority($c)) -lt (getOperatorPriority($func.Peek())))) {
                        [void]$res.Append($func.Pop());
                    }
                }
            }
            $func.Push($c);
        }
	}
	while ($func.Count -ne 0) {
        [void]$res.Append($func.Pop());
    }

	return $res.ToString();
}

Export-ModuleMember -Function toPostfix;