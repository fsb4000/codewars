Import-Module  $PSScriptRoot/solution.psm1

function myAssert ([bool]$condition)
{
    if (-not $condition) {
        throw "assertion failed";
    }
}

function Get-ModelSolution ([int[]]$values)
{
	[bool[]]$numbers = @($false) * 10;
    foreach ($value in $values) {
        myAssert($value -gt 0);
        myAssert($value -lt 10);
        $numbers[$value] = $true;
    }
    [UInt64]$res = 0;
    for ([int]$i = 1; $i -lt 10; ++$i) {
        if ($numbers[$i]) {
            $res = $res * 10 + $i;
        }
    }

    return $res;
}

Describe "Get-MinValue" {
	it "should return 13 when input is [1, 3, 1]" {
        [UInt64]$expected = 13;
		[int[]]$array = @(1, 3, 1);
        [UInt64]$actual = Get-MinValue($array);

        $actual | Should Be $expected;
    }

	 it "should return 457 when input is [4, 7, 5, 7]" {
		[UInt64]$expected = 457;
		[int[]]$array = @(4, 7, 5, 7);
        [UInt64]$actual = Get-MinValue($array);

        $actual | Should Be $expected;
    }

    it "should return 148 when input is [4, 8, 1, 4]" {
		[UInt64]$expected = 148;
		[int[]]$array = @(4, 8, 1, 4);
        [UInt64]$actual = Get-MinValue($array);

        $actual | Should Be $expected;
    }

    it "should return 579 when input is [5, 7, 9, 5, 7]" {
		[UInt64]$expected = 579;
		[int[]]$array = @(5, 7, 9, 5, 7);
        [UInt64]$actual = Get-MinValue($array);

        $actual | Should Be $expected;
    }

    it "should return 678 when input is [6, 7, 8, 7, 6, 6]" {
		[UInt64]$expected = 678;
		[int[]]$array = @(6, 7, 8, 7, 6, 6);
        [UInt64]$actual = Get-MinValue($array);

        $actual | Should Be $expected;
    }

    it "should return 45679 when input is [5, 6, 9, 9, 7, 6, 4]" {
		[UInt64]$expected = 45679;
		[int[]]$array = @(5, 6, 9, 9, 7, 6, 4);
		[UInt64]$actual = Get-MinValue($array);

		$actual | Should Be $expected;
    }

    it "should return 134679 when input is [1, 9, 1, 3, 7, 4, 6, 6, 7]" {
		[UInt64]$expected = 134679;
		[int[]]$array = @(1, 9, 1, 3, 7, 4, 6, 6, 7);
        [UInt64]$actual = Get-MinValue($array);

        $actual | Should Be $expected;
    }

    it "should return 356789 when input is [3, 6, 5, 5, 9, 8, 7, 6, 3, 5, 9]" {
		[UInt64]$expected = 356789;
		[int[]]$array = @(3, 6, 5, 5, 9, 8, 7, 6, 3, 5, 9);
        [UInt64]$actual = Get-MinValue($array);

        $actual | Should Be $expected;
    }

	it "should pass random tests" {
		[Random]$rnd = New-Object -TypeName "System.Random";
		
		for ([int]$i = 0; $i -lt 100; ++$i) {
			[int]$randomTestInputSize = $rnd.Next(3, 16); # Vector size range: [3, 16)
			[int[]]$random_input = @(0) * $randomTestInputSize;
            
			for([int]$j = 0; $j -lt $randomTestInputSize; ++$j) {
			$random_input[$j] = $rnd.Next(1, 10); # Element value range: [1, 10)
			}
			[UInt64]$expected = Get-ModelSolution($random_input);
			[UInt64]$actual = Get-MinValue($random_input);
        
			$actual | Should Be $expected;
		}
	}
}
