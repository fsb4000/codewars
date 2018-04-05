Import-Module  $PSScriptRoot\solution.psm1

Describe "toPostfix" {
	It 'should return "34+" when input is "3+4"' {
		toPostfix ("3+4") | Should Be "34+"
	}

	It 'should return "342*15-2^/+" when input is "3+4*2/(1-5)^2"' {
		toPostfix ("3+4*2/(1-5)^2") | Should Be "342*15-2^/+"
	}

	It 'should return "275*+" when input is "2+7*5"' {
		toPostfix ("2+7*5") | Should Be "275*+"
	}

	It 'should return "33*71+/" when input is "3*3/(7+1)"' {
		toPostfix ("3*3/(7+1)") | Should Be "33*71+/"
	}

	It 'should return "562-9*+371-^+" when input is "5+(6-2)*9+3^(7-1)"' {
		toPostfix ("5+(6-2)*9+3^(7-1)") | Should Be "562-9*+371-^+"
	}

	It 'should return "54-1-95/2/+71/7/-" when input is "(5-4-1)+9/5/2-7/1/7"' {
		toPostfix ("(5-4-1)+9/5/2-7/1/7") | Should Be "54-1-95/2/+71/7/-"
	}
}