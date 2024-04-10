#param([Int] $N)
#param([Int] $M)

if ($args.Count -eq 2) {
    $n = $args[0]
    $m = $args[1]
}else{
    [int]$n=read-host "Elso szam"
    [int]$m=read-host "Masodik szam"
}

write-output ($n*$m) >> ki.txt 
write-output ($n+$m) >> ki.txt 
write-output ([math]::sqrt($n)) >> ki.txt 
write-output ([math]::sqrt($m)) >> ki.txt    