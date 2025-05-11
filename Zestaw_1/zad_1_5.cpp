// Zmodyfikuj program z poprzedniego zadania tak, żeby korzystał z wyliczonych wcześniej wartości (nie powtarzał ich wyliczania) do wyznaczenia następnych. Na przykład, żeby pytał, który element ciągu ma wyliczyć i jeśli program już wcześniej wyliczył niższe wartości, to miał je zapamiętane i wykorzystał.


#include <iostream>
#include <algorithm>

#define N 100

using namespace std;

unsigned long long fib_table(unsigned long long i, int *tab);


int main()
{
    unsigned long long k;
    unsigned long long i;

    int tab[N];
    fill(tab, tab + N, -1); // wypełniamy tablicę -1
    tab[0] = 0;
    tab[1] = 1;

    cout << "Który wyraz ciągu fibonacciego wyliczyć? ";
    cin >> k;

    for (i = 0; i <= k; ++i) {
        cout << fib_table(i, tab) << endl;
    }

    return 0;
}


unsigned long long fib_table(unsigned long long i, int *tab)
{
    int j;

    if (tab[i] != -1) { // wyraz był już wcześniej wyliczony
        return tab[i];
    }
    else {
        tab[i] = tab[i-2] + tab[i-1];
        return tab[i];
    }

}