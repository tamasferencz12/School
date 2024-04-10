if($args.Count -eq 0){
    write-output "hiba"
}else{
    $fnev = $args[0]
    if (Test-Path $fnev) {
        $f = get-content $fnev
        foreach ($sor in $f) {
            if($sor -match "^[0-9]*$"){
                write-output $sor
            }
        }
    }else{
        write-output "hiba"
    }
}

#int ^[0-9]*$
#float
#text ^[a-zA-Z ]*$