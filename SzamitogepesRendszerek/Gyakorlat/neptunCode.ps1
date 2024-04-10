if($args.Count -eq 0){
    write-output "hiba"
}else{
    $fnev=$args[0]
    if(Test-Path $fnev){
        $f=get-content $fnev
        $generator=New-Object System.Random
        foreach($nev in $f){
            $neptun = ""
            for($i=1;$i -le 6;$i++){
                $v=$generator.Next(34)
                if($v -lt 24){
                    [Char]$betu = $v+65
                }else{
                    [Char]$betu = $v-24+48
                }
                $neptun += $betu
            }
            write-output "$nev $neptun" >> neptunkodok.txt
        }
    }else{
        write-output "hiba2"
    }
}