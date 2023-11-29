#!/bin/bash

# Változók az elérési útvonalakhoz
FAT_FILE="FAT.dat"

# Ellenőrizzük, hogy létezik-e a FAT fájl, ha nem, létrehozzuk
if [ ! -e "$FAT_FILE" ]; then
    touch "$FAT_FILE"
fi

# Ellenőrizzük a kapcsolókat és végrehajtjuk a megfelelő műveletet
while [ "$#" -gt 0 ]; do
    case "$1" in
        -lista)
            cat "$FAT_FILE"
            ;;
        -szabad)
            szabad_blokkszam=$(grep -c 'S' "$FAT_FILE")
            echo "Szabad blokkok száma: $szabad_blokkszam"
            ;;
        -max)
            max_szabad_blokkszam=$(grep -o 'S*' "$FAT_FILE" | awk '{ print length }' | sort -n | tail -1)
            echo "A leghosszabb összefüggő szabad blokksorozat hossza: $max_szabad_blokkszam"
            ;;
        -foglal)
            shift
            meret="$1"
            szabad_blokkok=$(grep -o 'S*' "$FAT_FILE")
            
            for sorozat in $szabad_blokkok; do
                if [ ${#sorozat} -ge "$meret" ]; then
                    hely=$(grep -m 1 "$sorozat" "$FAT_FILE")
                    hely_szam=$(echo "$hely" | cut -d ':' -f 1)
                    sorozat_megfelelo=$(echo "$sorozat" | head -c "$meret")
                    sed -i "${hely_szam}s/$sorozat_megfelelo/$(printf '%*s' ${#sorozat_megfelelo} | tr ' ' 'F')/" "$FAT_FILE"
                    echo "Foglalt blokkok: $sorozat_megfelelo"
                    break
                fi
            done
            ;;
        *)
            echo "Ismeretlen kapcsoló: $1"
            ;;
    esac
    shift
done
