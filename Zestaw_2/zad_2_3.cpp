/*
Napisz funkcję: auto fun(const auto& arg), którą wywołasz z argumentem typu initializer_list<T> (proszę sprawdzić, że nie da się wstawić np. {1,2,3} bo to samo w sobie nie jest typem, ale można zrobić linijkę wcześniej 
auto arg = {1,2,3}; i podstawić arg). W funkcji, za pomocą iteratora pozyskanego metodą begin(), przejść po całym kontenerze arg i policzyć sumę z argumentów. Funkcja fun niech zwróci wartość tej sumy.
*/

#include <iostream>
#include <initializer_list>

using namespace std;

template<typename T>


auto fun(const T& arg) {
    auto iter = arg.begin(); // wskaźnik na pierwszy element
    auto sum = *iter; // wartość pod wskaźnikiem na pierwszy element
    iter++; // przesunięcie wskaźnika
    while (iter != arg.end()) { // sumowanie kolejnych wartości z kontenera
        sum += *iter;
        iter++;
    }

    return sum;
}

int main() {
    // przykładowa lista typu initializer_list<int>
    auto arg_int = {1, 2, 3};
    cout << "Suma argumentow kontenera arg_int: " << fun(arg_int) << endl;

    // przykłaSdowa lista typu initializer_list<double>
    auto arg_double = {1.5, 2.7, 3.2};
    cout << "Suma argumentow kontenera arg_double: " << fun(arg_double) << endl;

    return 0;
}
