Import-Module  $PSScriptRoot/solution.psm1

Describe "Get-CenturyFromYear" {
	it "should return 18 when input is 1705" {
        [int]$expected = 18;
        [int]$actual = Get-CenturyFromYear(1705);

        $actual | Should Be $expected;
    }

	it "should return 19 when input is 1900" {
        [int]$expected = 19;
        [int]$actual = Get-CenturyFromYear(1900);

        $actual | Should Be $expected;
    }

	it "should return 17 when input is 1601" {
        [int]$expected = 17;
        [int]$actual = Get-CenturyFromYear(1601);

        $actual | Should Be $expected;
    }

	it "should return 20 when input is 2000" {
        [int]$expected = 20;
        [int]$actual = Get-CenturyFromYear(2000);

        $actual | Should Be $expected;
    }

	it "should pass random tests" {
		function Get-ModelSolution ([int]$year)
		{
			return [math]::Truncate(($year + 99) / 100);
		}
		[Random]$rnd = New-Object -TypeName "System.Random";
		
		for ([int]$i = 0; $i -lt 100; ++$i) {
			[int]$year = $rnd.Next(1, 1000001);
			[int]$expected = Get-ModelSolution($year);
			[int]$actual = Get-CenturyFromYear($year);
        
			$actual | Should Be $expected;
		}
	}
}
