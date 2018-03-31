Import-Module  $PSScriptRoot\solution.psm1

Describe "Get-Solution" {
		It 'should return -1 when input is "0()" 0' {
			Get-Solution "0()" 0 | Should Be -1
		}

		It 'should return 1 when input is "()" 0' {
			Get-Solution "()" 0 | Should Be 1
		}

		It 'should return 10 when input is "((1)23(45))(aB)" 0' {
			Get-Solution "((1)23(45))(aB)" 0 | Should Be 10
		}

		It 'should return 3 when input is "((1)23(45))(aB)" 1' {
			Get-Solution "((1)23(45))(aB)" 1 | Should Be 3
		}

		It 'should return -1 when input is "((1)23(45))(aB)" 3' {
			Get-Solution "((1)23(45))(aB)" 3 | Should Be -1
		}

		It 'should return 9 when input is "((1)23(45))(aB)" 6' {
			Get-Solution "((1)23(45))(aB)" 6 | Should Be 9
		}

		It 'should return 14 when input is "((1)23(45))(aB)" 11' {
			Get-Solution "((1)23(45))(aB)" 11 | Should Be 14
		}

		It 'should return 28 when input is "(g(At)IO(f)(tM(qk)YF(n)Nr(E)))" 11' {
			Get-Solution "(g(At)IO(f)(tM(qk)YF(n)Nr(E)))" 11 | Should Be 28
		}

		It 'should return -1 when input is "(g(At)IO(f)(tM(qk)YF(n)Nr(E)))" 28' {
			Get-Solution "(g(At)IO(f)(tM(qk)YF(n)Nr(E)))" 28 | Should Be -1
		}

		It 'should return 29 when input is "(g(At)IO(f)(tM(qk)YF(n)Nr(E)))" 0' {
			Get-Solution "(g(At)IO(f)(tM(qk)YF(n)Nr(E)))" 0 | Should Be 29
		}

		It 'should return 22 when input is "(>_(va)``?(h)C(as)(x(hD)P|(fg)))" 19' {
			Get-Solution "(>_(va)``?(h)C(as)(x(hD)P|(fg)))" 19 | Should Be 22
		}
}