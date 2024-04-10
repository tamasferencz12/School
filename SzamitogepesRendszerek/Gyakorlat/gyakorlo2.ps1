#param ([int] $n)
#param ([char] $name)

if ($args.Count -eq 2) {
    $n = $args[0]
    $name = $args[1]
}else{
    [int]$n=read-host "Elso szam"
    [String]$name=read-host "Nev"
}

for ($i = 0; $i -lt $n; $i++) {
    write-output $name
}