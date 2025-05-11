/*** ZADANIE 4 *** 1 PKT ***
Mamy liste wyrazy. Mamy tez pusta liste slowa. Za pomoca algorytmu copy_if oraz
obiektu funkcyjnego Samogloska wpisz, zawsze wstawiajac na poczatku, te slowa
z listy wyrazy, które zaczynaja sie na samogloske. Postepuj wedlug ponizszych 
wskazowek w komentarzach.
****************************/

#include <iostream>
#include <string>
#include <cctype>
#include <list>
#include <algorithm>
#include <iterator>

class Samogloska {
public:
    bool operator()(const std::string &wyraz) const
    {
        if (wyraz.length() == 0) {
            return false;
        }
        std::string samogloski {"aeiouy"};

        if (samogloski.find(std::tolower(wyraz[0])) != std::string::npos) {
            return true;
        } else {
            return false;
        }
    }
    // przeciazyc operator funkcyjny, ktory sprawdzi, czy pierwsza litera stringu,
    // wielka lub mala, jest samogloska, czyli: a, e, i, o, u, y

};

int main() {

    std::list<std::string> wyrazy { "Eskadra", "pustynia", "oaza", "manna", "youtube", "iota", "Uniwersytet" };
    std::list<std::string> slowa; // do listy zapisz tylko slowa na samogloske z przodu

    Samogloska samogloska;
    // uzyj std::copy_if oraz obiektu funkcyjnego Samogloska, zeby wpisac z przodu! listy
    // te wyrazy, ktore zaczynaja sie na samogloske

    // front_inserter do wpisywania z przodu listy
    std::copy_if(wyrazy.begin(), wyrazy.end(), std::front_inserter(slowa), samogloska); 

    
    // wypisz zawartosc listy slowa
    for (auto napis: slowa) {
        std::cout << napis << std::endl;
    }

}

