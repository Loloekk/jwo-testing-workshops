#!/bin/bash

g++ solve.cpp -o solve
g++ checker.cpp -o checker #Już zedytowana linia (kompilujemy checker.cpp) 


for ((i=1; i<=3; i++))
do
   
    # uruchamiamy solve i brut
    ./solve < in/roz$i.in > out.out

    # porównanie z ignorowaniem białych znaków
    if ./checker in/roz$i.in out/roz$i.out out.out > /dev/null; then # Już zedytowana linia (sprawdzamy poprawność za pomocą checker a nie diff)
        echo "$i [OK]"
    else
        echo "$i [FAIL]"
    fi
done

