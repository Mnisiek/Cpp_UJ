// Napisz funkcję wyliczającą kolejne wyrażenia ciągu Fibonacciego
// a. w wersji rekurencyjnej (czyli funkcja wywołuje samą siebie)
// b. w wersji z jedną pętlą for


#include <iostream>
#include <string>

using namespace std;

unsigned long long fib_rek(unsigned long long i);
unsigned long long fib_iter(unsigned long long i);


int main()
{
    unsigned long long k = 45;
    unsigned long long i;
    char function_mode;

    cout << "Wybierz, jak wyliczać wyrazy ciągu:" << endl;
    cout << "'r' - jeśli rekurencyjnie, 'i' - iteracyjnie, 'b' - oba sposoby: ";
    cin >> function_mode;

    for (i = 0; i <= k; ++i) {
        if (function_mode == 'r') {
            cout << fib_rek(i) << endl;
        }
        else if (function_mode == 'i') {
            cout << fib_iter(i) << endl;
        }
        else if (function_mode == 'b') {
            cout << fib_rek(i) << endl;
            cout << fib_iter(i) << endl;
        }
        else {
            cout << "Błąd, nieznana opcja" << endl;
            return 1;
        }
    }

    return 0;
}


unsigned long long fib_rek(unsigned long long i)
{
    if (i == 0) {
        return 0;
    }
    else if (i == 1) {
        return 1;
    }
    else {
        return fib_rek(i-1) + fib_rek(i-2); // kolejny wyraz ciągu jest sumą dwóch poprzednich
    }

}


unsigned long long fib_iter(unsigned long long i)
{
    unsigned long long a, b, c;
    a = 1;
    b = 0;

    for ( ; i > 0; --i) { // dekrementacja i jako licznik kolejnych wyrazów, które pozostały do obliczenia
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}