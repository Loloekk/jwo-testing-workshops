#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4) return 1;

    ifstream fin(argv[1]);   // Wejście (in)
    ifstream fref(argv[2]);  // Poprawne wyjście (out)
    ifstream fout(argv[3]);  // Wyjście waszego kodu

    // Aby wczytać zmienną z pliku wejścia robimy fin >> nazwa_zmiennej;
    // Analogicznie aby wczytać z pliku poprawnego wyjścia fref >> nazwa_zmiennej;
    // I z pliku wyjścia waszego kodu fout >> nazwa_zmiennej;
       

    // Zwracamy 1 gdy znajdziemy błąd return 1;
    // Zwracamy 0 gdy odpowiedź jest poprawna
    return 0;
    // W ten sposób możemy porównywać bruta z głównym rozwiązaniem gdy jest wiele poprawnych wyjść.
}