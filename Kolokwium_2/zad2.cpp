/*** ZADANIE 2 *** 1 PKT ***
Mamy wektor obiektow std::string o nazwie slowa.
Napisz wyrazenie Lambda porownujace dwa stringi operatorem < 
wedlug ich dlugosci i zwroc wynik. Nastepnie uzyj to wyrazenie 
Lambda w algorytmie sort do posortowania wektora slowa. 
Wypisz zawartosc wektora w dowolny sposob.
****************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> slowa = {"abc", "ABCD", "XYZUVW", "abrakadabra", "never"};

    // sortowanie wektora slowa według długości jego elementów (od najdłuższego do najkrótszego)
    std::sort(slowa.begin(), slowa.end(), [](std::string napis1, std::string napis2) { return (napis1.length() > napis2.length()); } );

    for (auto napis: slowa) {
        std::cout << napis << std::endl;
    }

}
