$szt=get-content $args[0]

for ($i = 0; $i -lt $szt.Length; $i++) {
    $sor=$szt[$i]
    write-output "$i . $sor"
}