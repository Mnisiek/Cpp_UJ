#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

#define N 100000000

using namespace std;


long long NWD(long long a, long long b);
void RSA();
bool czy_pierwsza(long long n);

long long main()
{
    int i = 0;
    long long random_number;
    long long liczba;

    cout << "Podaj liczbę do zaszyfrowania" << endl;
    cin >> liczba;

    do {
        srand(std::time(nullptr));
        long long random_number = rand() % N;
    } while (czy_pierwsza(random_number));

}


long long NWD(long long a, long long b)
{
    long long t;

    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}


bool czy_pierwsza(long long n)
{
    if (n < 2)
        return false;

    for (long long d = 2; d*d <= n; d++)
        if (n % d == 0) {
            return false;
        }

    return true;
}


void RSA(long long p, long long q)
{
    long long phi, n, e, d;

    do
    {
        
    } while (p == q);

    phi = (p - 1) * (q - 1);
    n = p * q;

}