param([int]$e, [int]$u)
$numbers = $e..$u

function prim($n){
    $i=2
    while (( $i -lt [math]::sqrt($n)) -and ($n%$i -ne 0)){
        $i++
    }
    return $i -gt [math]::sqrt($n)
}

foreach ($number in $numbers) {
    if(prim($number)){
        write-output $number
    }
}