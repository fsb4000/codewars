Import-Module  $PSScriptRoot\solution.psm1

Describe "Get-IqTest" {
		It 'should return 1 when input is "1 2 2"' {
			Get-IqTest "1 2 2" | Should Be 1
		}

	    It 'should return 3 when input is "2 4 7 8 10"' {
			Get-IqTest "2 4 7 8 10" | Should Be 3
		}

		It 'should return 4 when input is "1 1 1 2"' {
			Get-IqTest "1 1 1 2" | Should Be 4
		}

		It 'should return 5 when input is "2 4 8 10 7"' {
			Get-IqTest "2 4 8 10 7" | Should Be 5
		}
}