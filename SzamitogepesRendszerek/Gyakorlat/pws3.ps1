if ($args.Count -eq 1) {
    $n = $args[0]
}
else {
    [int]$n=read-host "Egesz szamot"
}
$f=1
for ($i = 1; $i -le $n; $i++) {
    $f*=$i
}