#!/bin/sh

word=$2
num=$1

for (( i=1; i <= num; i++))
do
	for (( j=1; j <=i; j++)) 
	do
		echo -n "$word "
	done
	echo -e 
done
