#!/bin/sh

input=~/Desktop/SzamitogepesRendszerek/Gyakorlat/GyakorlasZH/szavak.txt

while read -r sor
do
	echo "$sor ${#sor}"
done < "$input"
