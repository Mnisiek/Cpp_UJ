
#include <iostream>
#include <list>
#include <set>
#include <algorithm>


int main()
{
    std::list<char> lista = {'a', 'c', 'b', 'd', 'f', 'e', 'h', 'g'};

    auto porownaj = [&lista](const auto& l, const auto& p) {
        // sprawdzamy, która litera występuje najpierw w liście
        return (std::distance(lista.begin(), std::find(lista.begin(), lista.end(), l)) < std::distance(lista.begin(), std::find(lista.begin(), lista.end(), p)));
    };

    std::set<char, decltype(porownaj)> mySet({'a', 'a' , 'a', 'g', 'c', 'b', 'f', 'h', 'c', 'e', 'd', 'e'}, porownaj);

    for (auto c : mySet) {
        std::cout << c;
    }
    std::cout << std::endl;


    return 0;
}