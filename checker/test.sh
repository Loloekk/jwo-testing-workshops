#!/bin/bash

g++ solve.cpp -o solve
#TODO


for ((i=1; i<=3; i++))
do
   
    # uruchamiamy solve i brut
    ./solve < in/roz$i.in > out.out

    # porównanie z ignorowaniem białych znaków
    if diff -w out.out out/roz$i.out > /dev/null; then # TODO
        echo "$i [OK]"
    else
        echo "$i [FAIL]"
    fi
done

