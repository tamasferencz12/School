#!/usr/bin/env bash

TEAMS="teams.dat"
HALLGATO="hallgato.dat"

function help() {
read -r -d '' help << EOM
==================================================================================
Hasznalat:
   bash ${1} [-help] [-leiras] [-peldak] [-lista oktatonev] [-hallgato hallgatonev] [-sok]
==================================================================================
EOM

echo "$help"
}


function oktato_kurzusai() {
    oktatok=$(cut -d ',' -f 3 $TEAMS | grep -i "$1" | uniq)
    if [ -z "$oktatok" ]; then
       echo "Nem talalhato a '$1' nevu oktato."
       return 1
    fi
    lista=()
    while IFS= read -r line;
    do 
        lista+=("$line"); 
    done <<< "$oktatok"

    if [ "${#lista[@]}" -gt 1 ]; then
        echo "${#lista[@]} $1 nevu oktatot talaltunk. Adja meg a pontosan kire gondolt!"
        oktatonevek=$(printf "%s vagy " "${lista[@]}")
        n=${#oktatonevek}
        ((n-=6))
        echo "${oktatonevek:0:$n}?" # kiiratas nulladik indextol az n-ig
        return 2
    fi

    oktato=${lista[0]}
    kurzusok=$(grep -i "$1" $TEAMS | cut -d ',' -f 1 | tr '\n' , | sed 's/,/, /gi')
    if [ -z "$kurzusok" ]; then
        echo "$1 nem tart kurzusokat."
    else
        n=${#kurzusok}
        ((n-=2))
        echo "$oktato kurzusai: ${kurzusok:0:$n}"
    fi
}

function hallgato_tanarai() {
    hallgatok=$(cut -d ',' -f 1 $HALLGATO | grep -i "$1")
    if [ -z "$hallgatok" ]; then
       echo "Nem talalhato a '$1' nevu hallgato."
       return 1
    fi
    
    lista=()
    while IFS= read -r line;
    do 
        lista+=("$line"); 
    done <<< "$hallgatok"

    if [ "${#lista[@]}" -gt 1 ]; then
        echo "${#lista[@]} $1 nevu hallgatot talaltunk. Adja meg a pontosan kire gondolt!"
        diakok=$(printf "%s vagy " "${lista[@]}")
        n=${#diakok}
        ((n-=6))
        echo "${diakok:0:$n}?"
        return 2
    fi

    hallgato="${lista[0]}"
    teams=$(grep -i "$hallgato" $HALLGATO)
    #echo "$teams"
    IFS=, read -ra kurzusok <<< "$teams"
    tanarok=""
    for kurzus in "${kurzusok[@]}"
    do
        if [ "$kurzus" != "$hallgato" ]; then
            tanar=$(grep -i "$kurzus" $TEAMS | cut -d ',' -f 3)
            if [ -z "$tanarok" ]; then
                tanarok="[$kurzus]$tanar"
            else
                tanarok="$tanarok, [$kurzus]$tanar"
            fi
        fi
    done
    echo "$hallgato tanarai: $tanarok"    

}

function sok() {
    info=$(cut -d ',' -f 3 $TEAMS | sort | uniq -c | sort -rn | head -n 1)
    #echo "$info"
    IFS=' ' read -ra kurzusok <<< "$info"
    kurzusok_szama="${kurzusok[0]}"
    oktato_neve=""
    for((i=1;i<${#kurzusok[@]};i++))
    do
        oktato_neve="$oktato_neve ${kurzusok[$i]}"
    done
    echo "A legtobb meghirdetett kurzus $kurzusok_szama, oktato: $oktato_neve"
    oktato_kurzusai "$oktato_neve"
}

if [ $# -lt 1 ]; then
    help "$0"
    exit 1
fi


case $1 in
    -help)
        help;;
    -leiras)
        cat leiras.txt;;
    -peldak)
        cat peldak.txt;;        
    -lista)
        shift
        if [ -z "$1" ]; then
            echo "Adja meg az oktato nevet!"
            help "$0" 
            exit 1
        fi
        oktato_kurzusai "$1"
        ;;    
     -hallgato)
        shift
        if [ -z "$1" ]; then
            echo "Adja meg a hallgato nevet!"
            help "$0" 
            exit 1
        fi
        hallgato_tanarai "$1"
        ;;
    -sok)
        sok;;   
     *)
        echo "Ismeretlen kapcsolo."
        echo "Probalja: bash $0 -help"    
        ;;       
esac

