
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>


int main()
{
    std::vector<int> vec(100);
    std::iota(vec.begin(), vec.end(), 1);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vec.begin(), vec.end(), g);

    std::cout << "Zawartość wektora po wymieszaniu:" << std::endl;
    for (auto num: vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;

    std::sort(vec.begin(), vec.end(), std::greater<int>());
    std::cout << "Zawartość wektora po posortowaniu (od największej do najmniejszej wartości):" << std::endl;
    for (auto num: vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;

    struct {
        bool operator()(int a, int b) const {
            return a > b;
        }
    } wieksza_niz;

    std::sort(vec.begin(), vec.end(), wieksza_niz);
    std::cout << "Zawartość wektora po posortowaniu (z wykorzystaniem obiektu funkcyjnego wieksza_niz):" << std::endl;
    for (auto num: vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;

    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        std::string str_a = std::to_string(a);
        std::string str_b = std::to_string(b);

        // jeżeli pierwsza cyfra jest taka sama, to porównujemy wartości liczb
        if (str_a[0] == str_b[0]) {
            return a < b;
        } else {
            // jeżeli pierwsze cyfry są różne, to porównujemy tylko je
            return str_a[0] < str_b[0];
        }
        });
    std::cout << "Zawartość wektora po posortowaniu (kryterium 1, 10, 11, 12, 13 ...):" << std::endl;
    for (auto num: vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl << std::endl;


    return 0;
}