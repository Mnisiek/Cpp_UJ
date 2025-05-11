/*** ZADANIE 3 *** 2 PKT ***
Utworz wektor int'ow o wielkosci 10.
Wypelnij go losowymi wartosciami w nastepujacy sposob:
z pomoca random_device, mt19937 oraz uniform_int_distribution oraz
z pomoca algorytmu generate (mozna sprawdzic na cppreference.com),
w ktorym trzecim argumentem ma byc wyrazenie Lambda robiace losowanie.
Wypisz zawartosc wektora.
Nastepnie za pomoca algorytmu transform oraz wyrazenia Lambda
przelicz ten sam wektor, wypelniajac go kwadratem pierwotnych wartosci.
Ponownie wypisz zawartosc wektora.
***************************/

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

int main() {
    std::vector<int> wektor1(10);

    // pierwszy sposób
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 10);

    for (int n = 0; n < 10; ++n) {
        wektor1[n] = distrib(gen);
    }

    for (auto num: wektor1) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;

    // drugi sposób
    std::generate(wektor1.begin(), wektor1.end(), []() { return rand() % 10; } );

    for (auto num: wektor1) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;

    // podnoszenie elementów wektora do kwadratu
    std::transform(wektor1.begin(), wektor1.end(), wektor1.begin(), [](int num) { return num*num; } );

    for (auto num: wektor1) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;

}
