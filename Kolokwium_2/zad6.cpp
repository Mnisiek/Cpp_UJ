/*** ZADANIE 6 *** 1 PKT ***
Mamy wypelniona mape mapais, oraz pusta mape mapasi. Mamy tez funkcje zamieniacz,
ktora zwraca pare z zamienionymi miejscami typami. Napisz z uzyciem algorytmu
transform przepisanie mapy mapais do mapysi w taki sposob, ze uzyty bedzie
zamieniacz - zaadaptowany za pomoca bind, a wstawianie do mapasi bedzie
za pomoca inserter. Na koniec wypisz cala zawartosc mapasi (oba pola, first i second).
****************************/

#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <algorithm>

using namespace std;
using namespace std::placeholders;

pair<string,int> zamieniacz(const pair<int,string>& c) {
    return pair<string,int>(c.second, c.first);
}


int main() {
    map<int,string> mapais {{3,"aaa"},{4,"bbb"},{2,"fff"},{1,"ccc"},{5,"ddd"},{7,"ggg"},{6,"hhh"}};
    map<string,int> mapasi;

    // przepisanie mapy mapais do mapasi z zamienionymi first i second
    transform(mapais.begin(), mapais.end(), inserter(mapasi, mapasi.begin()), bind(zamieniacz, _1));

    for (auto element: mapasi) {
        cout << element.first << ", " << element.second << endl;
    }

}