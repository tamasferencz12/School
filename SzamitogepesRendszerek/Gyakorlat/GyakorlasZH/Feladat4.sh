#!/bin/sh

input=~/Desktop/SzamitogepesRendszerek/Gyakorlat/GyakorlasZH/szamok.txt
result=0

while read -r sor
do
	max=0
        for num in $sor; do
		if [ "$num" -gt "$max" ]; then
			max="$num"
		fi
	done
	result=$((result + max))
done < "$input"

echo "Az eredmeny: $result"
