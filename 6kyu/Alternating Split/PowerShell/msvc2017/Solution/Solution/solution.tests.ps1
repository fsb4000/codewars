Import-Module  $PSScriptRoot\solution.psm1

Describe "Encrypt" {
	It 'should return "This is a test!" when input is "This is a test!" -1' {
		Encrypt "This is a test!" -1 | Should Be "This is a test!"
	}

	It 'should return "This is a test!" when input is "This is a test!" 0' {
		Encrypt "This is a test!" 0 | Should Be "This is a test!"
	}

	It 'should return "hsi  etTi sats!" when input is "This is a test!" 1' {
		Encrypt "This is a test!" 1 | Should Be "hsi  etTi sats!"
	}

	It 'should return "s eT ashi tist!" when input is "This is a test!" 2' {
		Encrypt "This is a test!" 2 | Should Be "s eT ashi tist!"
	}

	It 'should return " Tah itse sits!" when input is "This is a test!" 3' {
		Encrypt "This is a test!" 3 | Should Be " Tah itse sits!"
	}

	It 'should return "This is a test!" when input is "This is a test!" 4' {
		Encrypt "This is a test!" 4 | Should Be "This is a test!"
	}

	It 'should return "" when input is "" 3' {
		Encrypt "" 3 | Should Be ""
	}
}

Describe "Decrypt" {
	It 'should return "This is a test!" when input is "This is a test!" -1' {
		Decrypt "This is a test!" -1 | Should Be "This is a test!"
	}

	It 'should return "This is a test!" when input is "This is a test!" 0' {
		Decrypt "This is a test!" 0 | Should Be "This is a test!"
	}


	It 'should return "This is a test!" when input is "hsi  etTi sats!" 1' {
		Decrypt "hsi  etTi sats!" 1 | Should Be "This is a test!"
	}

	It 'should return "This is a test!" when input is "s eT ashi tist!" 2' {
		Decrypt "s eT ashi tist!" 2 | Should Be "This is a test!"
	}

	It 'should return "This is a test!" when input is " Tah itse sits!" 3' {
		Decrypt " Tah itse sits!" 3 | Should Be "This is a test!"
	}

	It 'should return "This is a test!" when input is "This is a test!" 4' {
		Decrypt "This is a test!" 4 | Should Be "This is a test!"
	}

	It 'should return "" when input is "" 3' {
		Decrypt "" 3 | Should Be ""
	}
}