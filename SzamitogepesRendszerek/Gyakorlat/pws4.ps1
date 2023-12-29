$osszeg=0
if ($args.Length -eq 0)
{
    foreach ($item in $input)
    {
        $osszeg+=$item
    }
    write-output $osszeg
}
else
{
    foreach ($item in $args)
    {
        $osszeg+=$item
    }
    write-output $osszeg
}