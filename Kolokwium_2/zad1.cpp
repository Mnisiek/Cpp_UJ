/*** ZADANIE 1 *** 1 PKT ***
Mamy wektor liczb. Napisz wyrazenie Lambda, które przyjmuje przez 
argument funkcyjny referencje do tego wektora, a nastepnie oblicza 
sume liczb parzystych i zwraca wynik.  
****************************/

#include <iostream>
#include <vector>


int main() {
    std::vector<int> liczby = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto suma = [](std::vector<int> &liczby) { int res = 0; for (auto num: liczby) { if (!(num % 2)) res += num; } return res; }; // tu napisz wyrazenie Lambda


// kodu ponizej nie zmieniac
    int wynik = suma(liczby);
    std::cout << "Suma liczb parzystych: " << wynik << std::endl;
}

