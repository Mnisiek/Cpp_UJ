#include <iostream>
#include "klasa.h"
using namespace std;

// W pliku klasa.h jest zdefiniowana klasa o nazwie Litera
// Prosze tak rozwinac zawartosc plikow, aby dzialal ponizszy kod.
// *** 2 pkt ***

// przyklad kompilowania "z reki"
// g++ -std=c++20 main.cpp klasa.cpp -o program

// ---------------- ponizej nic nie zmieniac -----------------
int main() {
   Litera k1('A');
   Litera k2 = k1;
   k1 = k2;
   cout << "Ltery: " << k1.print() << " " << k2.print() << endl;
}
