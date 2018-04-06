function validParentheses ([string]$parens)
{
    [int]$brackets = 0;
    foreach($c in [char[]]$parens) {
        if ($c -eq '(') {
            ++$brackets;
        } elseif ($c -eq ')') {
            --$brackets;
            if ($brackets -lt 0) {
                return $false;
            }
        }
    }

    return $brackets -eq 0;
}

Export-ModuleMember -Function validParentheses;