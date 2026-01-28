#!/bin/bash

# Kompilacja plików
g++ solve.cpp -o solve
g++ brut.cpp -o brut
g++ gen.cpp -o gen

# Pętla od 1 do 1000
for ((i=1; i<=1000; i++))
do
    echo -n $i
    # Generowanie testu (przekazujemy i jako ziarno bezpośrednio)
    echo $i > seed.txt
    ./gen < seed.txt > test.in

    # Uruchomienie programów
    ./solve < test.in > solve.out
    ./brut < test.in > brut.out

    # Porównanie wyników
    if diff -w solve.out brut.out > /dev/null; then
        echo " OK"
    else
        echo " FAIL"
        echo "Failing seed: $i"
        exit 1
    fi
done