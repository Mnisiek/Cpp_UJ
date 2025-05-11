
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>


int main()
{
    std::vector<int> vec = {2, 5, 64, 8, 47, 1, 27, 9, 38, 25, 35, 86, 21, 94, 38, 45, 3};

    auto polacz = [](std::string napis, int liczba) {
        return napis + "-" + std::to_string(liczba);
    };

    auto s = std::accumulate(std::next(vec.begin()), vec.end(), std::to_string(vec[0]), polacz);

    std::cout << s << std::endl;


    return 0;
}