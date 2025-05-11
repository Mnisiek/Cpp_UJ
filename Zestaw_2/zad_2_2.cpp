/*
Wygeneruj na początek 10000 losowych liczb w zakresie od 1 do 10000 z rozkładem jednorodnym, zapisując je w obiekcie typu std::vector<int>, praktycznie gotowy przykład:
https://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution
Następnie napisz algorytm sortowania Quicksort, z pivotem w środku przedziału. Opis algorytmu bez problemu można znaleźć w Internecie. Oczywiście proszę wypisać liczby przed i po posortowaniu.
*/

#include <iostream>
#include <random>
#include <vector>

#define N 10000 // liczba generowanych liczb

using namespace std;

void quicksort(vector <int>& result, int low, int high);

int main()
{
    vector <int> result(N);
    int i;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 10000);

    for (i = 0; i < N; ++i) { // wpisywanie generowanych liczb do wektora
        result[i] = distrib(gen);
    }

    // elementów jest aż 10000, więc lepiej wypisać tylko ich część
    cout << "Pierwsze 10 elementow przed posortowaniem:" << endl;
    for (i = 0; i < 10; ++i) {
        cout << result[i] << endl;
    }

    quicksort(result, 0, N-1); // wywołanie funkcji quicksort

    // znów tylko 10 pierwszych w celu porównania po sortowaniu
    cout << "Pierwsze 10 elementow po posortowaniu:" << endl;
    for (i = 0; i < 10; ++i) {
        cout << result[i] << endl;
    }

    return 0;
}

// implementacja algorytmu quicksort z wyborem pivota w środku przedziału
void quicksort(vector<int>& result, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = result[(low + high) / 2];

    while (i <= j)
    {
        while (result[i] < pivot)
        {
            i++;
        }

        while (result[j] > pivot)
        {
            j--;
        }

        if (i <= j)
        {
            swap(result[i], result[j]); // funkcja swap() zamienia elementy
            i++;
            j--;
        }
    }

    if (low < j)
    {
        quicksort(result, low, j);
    }

    if (i < high)
    {
        quicksort(result, i, high);
    }
}
