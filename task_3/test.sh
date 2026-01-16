#!/bin/bash

g++ -O2 -std=c++17 roz.cpp -o roz
if [ $? -ne 0 ]; then
    echo "Błąd kompilacji"
    exit 1
fi

for i in $(seq 1 6); do
    infile="in/roz$i.in"
    outfile="out/roz$i.out"
    tmpout=$(mktemp)

    if [ ! -f "$infile" ] || [ ! -f "$outfile" ]; then
        echo "roz$i: ERR (brak pliku)"
        rm "$tmpout"
        continue
    fi

    start=$(date +%s.%N)
    timeout 3s ./roz < "$infile" > "$tmpout"
    status=$?
    end=$(date +%s.%N)

    time=$(echo "$end - $start" | bc)

    echo -n "roz$i: "

    if [ $status -eq 124 ]; then
        echo "TLE"
        rm "$tmpout"
        continue
    elif [ $status -ne 0 ]; then
        echo "ERR"
        rm "$tmpout"
        continue
    fi

    tle=$(echo "$time > 1.0" | bc)
    if [ "$tle" -eq 1 ]; then
        echo -n "TLE "
    fi

    diff -q "$tmpout" "$outfile" >/dev/null
    if [ $? -eq 0 ]; then
        echo "OK"
    else
        echo "ANS"
    fi

    rm "$tmpout"
done
