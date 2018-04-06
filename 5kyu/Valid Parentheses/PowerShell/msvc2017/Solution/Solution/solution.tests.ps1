Import-Module  $PSScriptRoot\solution.psm1

Describe "validParentheses" {
	It 'should return true when input is "()"' {
		validParentheses ("()") | Should Be $true
	}

	It 'should return false when input is "())"' {
		validParentheses ("())") | Should Be $false
	}

	It 'should return false when input is "("' {
		validParentheses ("(") | Should Be $false
	}

	It 'should return false when input is ")(()))"' {
		validParentheses (")(()))") | Should Be $false
	}

	It 'should return true when input is "(())((()())())"' {
		validParentheses ("(())((()())())") | Should Be $true
	}
}