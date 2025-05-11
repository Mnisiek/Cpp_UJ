#include <iostream>
#include "klasa.h"
using namespace std;

// W pliku klasa.h jest zdefiniowana klasa o nazwie Liczba
// Prosze tak rozwinac zawartosc plikow, aby dzialal ponizszy kod.
// *** 2 pkt ***

// przyklad kompilowania "z reki"
// g++ -std=c++20 main.cpp klasa.cpp -o program


// ---------------- ponizej nic nie zmieniac -----------------
int main() {
   Liczba k1(123);
   Liczba k2; 
   cout << "Wpisz liczbe: ";
   cin >> k2;
   cout << "Mamy: " << k1 << " " << k2 << endl;
}
