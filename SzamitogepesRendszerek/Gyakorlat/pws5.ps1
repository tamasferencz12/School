$delta=0
$eredm1=0
$eredm2=0

[int]$a = read-host "a"
[int]$b = read-host "b"
[int]$c = read-host "c"

$delta = $b * $b - 4*$a*$c

if($delta -lt 0){
    Write-Output "Nincs gyok!"
}else{
    $eredm1 = ((-1*$b) - [Math]::sqrt($delta)) / 2*$a
    $eredm2 = ((-1*$b) + [Math]::sqrt($delta)) / 2*$a
}

write-output $eredm1
write-output $eredm2
 