if($args.Count -eq 0){
    write-output "hiba2"
}else{
    $fnev=$args[0]
    if(Test-Path $fnev){

        $f=get-content $fnev
    
        foreach ($sor in $f){
            $sor.replace(" kukac ","@").replace(" dot ",".")
        }
    }else{
        write-output "hiba"
    }
}
