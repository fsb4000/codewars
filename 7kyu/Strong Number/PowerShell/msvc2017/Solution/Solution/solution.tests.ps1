Import-Module $PSScriptRoot/solution.psm1

Set-Variable -Name strong -Value "STRONG!!!!" -Option Constant;
Set-Variable -Name notStrong -Value "Not Strong !!" -Option Constant;

Describe "Get-CenturyFromYear" {
  It "should return strong when input is 1" {
    [string]$expected = $strong;
    [string]$actual = strongNumber (1);

    $actual | Should Be $expected;
  }

  It "should return strong when input is 2" {
    [string]$expected = $strong;
    [string]$actual = strongNumber (2);

    $actual | Should Be $expected;
  }

  It "should return strong when input is 145" {
    [string]$expected = $strong;
    [string]$actual = strongNumber (145);

    $actual | Should Be $expected;
  }

  It "should return notStrong when input is 7" {
    [string]$expected = $notStrong;
    [string]$actual = strongNumber (7);

    $actual | Should Be $expected;
  }

  It "should return notStrong when input is 93" {
    [string]$expected = $notStrong;
    [string]$actual = strongNumber (93);

    $actual | Should Be $expected;
  }

  It "should return notStrong when input is 185" {
    [string]$expected = $notStrong;
    [string]$actual = strongNumber (185);

    $actual | Should Be $expected;
  }

  It "should pass random tests" {
    function myAssert ([bool]$condition)
    {
      if (-not $condition) {
        throw "assertion failed";
      }
    }

    function fact ([int]$n)
    {
      [int]$res = 1;
      for ([int]$i = 1; $i -le $n;++ $i) {
        $res *= $i;
      }

      return $res;
    }

    function modelSolution ([int]$number)
    {
      myAssert ($number -gt 0);

      [int]$temp = $number;
      [int]$res = 0;
      while (($temp -gt 0) -and ($res -lt $number)) {
        $res += fact ($temp % 10);
        $temp /= 10;
      }
      if ($res -eq $number) {
        return "STRONG!!!!";
      }

      return "Not Strong !!";
    }

    [Random]$rnd = New-Object -TypeName "System.Random";

    for ([int]$i = 0; $i -lt 100;++ $i) {
      [int]$number = $rnd.Next(1,1000001);
      [string]$expected = strongNumber ($number);
      [string]$actual = modelSolution ($number);

      $actual | Should Be $expected;
    }
  }
}
