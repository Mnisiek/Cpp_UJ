/*** ZADANIE 5 *** 1 PKT ***
Mamy funkcje parzysta, sprawdzajaca, czy liczba jest parzysta.
Mamy wektor liczby, wypelniony liczbami.
Prosze za pomoca algorytmu remove_if oraz funkcji parzysta, 
zaadaptowanej za pomoca std::bind do bycia obiektem funkcyjnym
sprawic, zeby w wektorze zostaly same liczby nieparzyste.
I teraz wazna uwaga: remove_if nie usuwa elementow z kontenera,
tylko je przemieszcza, zwracajac iterator ustawiony na nowy adres 
konca kontenera. Od tego adresu, az do liczby.end(), trzeba
elemety usunac. Na koniec wypisac zawartosc, powinno byc: 1 3 5 7 9
****************************/

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std::placeholders;

bool parzysta(int liczba) {
    return liczba % 2 == 0;
}

int main() {
    std::vector<int> liczby = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // usuwanie liczb parzystych z vectora
    liczby.erase(std::remove_if(liczby.begin(), liczby.end(), std::bind(parzysta, _1)), liczby.end());

    for (auto num: liczby) {
        std::cout << num << std::endl;
    }
}
