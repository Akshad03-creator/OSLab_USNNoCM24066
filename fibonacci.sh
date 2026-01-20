#!/bin/bash
echo "Enter n:"
read n

a=1
b=1
echo "Fibonacci Series:"
echo -n "$a $b "

for ((i=3;i<=n;i++))
do
 c=$((a+b))
 echo -n "$c "
 a=$b
 b=$c
done
echo
