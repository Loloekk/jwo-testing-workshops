#include <bits/stdc++.h>
using namespace std;

int main() {
    // kompilacja
    system("g++ solve.cpp -o solve");
    system("g++ brut.cpp -o brut");
    system("g++ gen.cpp -o gen");

    for (int i = 1; i <= 1000; i++) {
        // seed = i
        cout<<i<<" ";
        system(("echo " + to_string(i) + " > seed.txt").c_str());

        // generowanie testu
        system("./gen < seed.txt > test.in");

        // uruchomienie solve i brut
        system("./solve < test.in > solve.out");
        system("./brut < test.in > brut.out");

        // porównanie (ignorujemy białe znaki)
        if (system("diff -w solve.out brut.out > /dev/null") == 0) {
            cout << " OK\n";
        } else {
            cout << " FAIL\n";
            cout << "Failing seed: " << i << "\n";
            return 0;
        }
    }

    return 0;
}