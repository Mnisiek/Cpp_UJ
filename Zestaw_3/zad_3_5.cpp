
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>

using namespace std;

#include <stdio.h>
#include <string.h>

#define N_MAX_INPUT 1000
#define N_MAX_OUTPUT (2*N_MAX_INPUT)


int multiply(char num1[], char num2[])
{
    int wynik[N_MAX_OUTPUT + 1];
    int i, j, n, m, temp;
    m = 0;

    if (num1[0] == '0' || num2[0] == '0') {
        printf("Wynik:\n0");
        return 0;
    }

    for (n = 0; n < N_MAX_OUTPUT; n++)
        wynik[n] = 0;

    for (i = strlen(num1) - 1; i >= 0; i--) {
        for (j = strlen(num2) - 1, n = N_MAX_OUTPUT - 1 - m; j >= 0; j--) {
            wynik[n] += (num2[j] - '0') * (num1[i] - '0');
            if (wynik[n] > 9) {
                temp = wynik[n];
                wynik[n] = temp % 10;
                wynik[n-1] += (temp / 10);
            }
            n--;
        }
        m++;
    }

    n = 0;
    while (wynik[n] == 0)
        n++;

    printf("Wynik:\n");
    for ( ; n < N_MAX_OUTPUT; n++)
        printf("%d", wynik[n]);

    return 0;
}

int nwd(int a, int b)
{
    int t;

    while (b != 0) {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}


int odwr_mod ( int a, int n )
{
    int a0, n0, p0, p1, q, r, t;

    p0 = 0; p1 = 1; a0 = a; n0 = n;
    q  = n0 / a0;
    r  = n0 % a0;
    while( r > 0 )
    {
        t = p0 - q * p1;
        if (t >= 0 )
            t = t % n;
        else
            t = n - ((-t) % n);
        p0 = p1; p1 = t;
        n0 = a0; a0 = r;
        q = n0 / a0;
        r = n0 % a0;
    }
    return p1;
}


void klucze_RSA()
{
    const int tp [10] = {11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
    int p, q, phi, n, e, d;

    cout << "Generowanie kluczy RSA\n"
            "----------------------\n\n";

// generujemy dwie różne, losowe liczby pierwsze

    do
    {
        p = tp[rand() % 10];
        q = tp[rand() % 10];
    } while (p == q);

    phi = (p - 1) * (q - 1);
    n = p * q;

// wyznaczamy wykładniki e i d

  for (e = 3; nwd(e, phi) != 1; e += 2 );
  d = odwr_mod (e, phi);

// gotowe, wypisujemy klucze

  cout << "KLUCZ PUBLICZNY\n"
          "wykladnik e = " << e
       << "\n    modul n = " << n
       << "\n\nKLUCZ PRYWATNY\n"
          "wykladnik d = " << d << endl;
}


int pot_mod ( int a, int w, int n )
{
    int pot, wyn, q;

// wykładnik w rozbieramy na sumę potęg 2
// przy pomocy algorytmu Hornera. Dla reszt
// niezerowych tworzymy iloczyn potęg a modulo n.

    pot = a; wyn = 1;
    for(q = w; q > 0; q /= 2)
    {
        if (q % 2) 
            wyn = (wyn * pot) % n;
        pot = (pot * pot) % n; // kolejna potęga
    }
    return wyn;
}

// Procedura kodowania danych RSA
//-------------------------------
void kodowanie_RSA( )
{
    int e, n, t;

    cout << "Kodowanie danych RSA\n"
            "--------------------\n\n"
            "Podaj wykladnik = "; cin  >> e;
    cout << "    Podaj modul = "; cin  >> n;
    cout << "----------------------------------\n\n"
            "Podaj kod RSA   = "; cin  >> t;
    cout << "\nWynik kodowania = " << pot_mod ( t, e, n ) << endl;
}

// ********************
// ** Program główny **
// ********************

int main( )
{

    char num1[N_MAX_INPUT + 1];
    char num2[N_MAX_INPUT + 1];

    printf("Podaj pierwsza liczbe: ");
    scanf("%s", num1);
    printf("Podaj druga liczbe: ");
    scanf("%s", num2);

    multiply(num1, num2);

    int w;

    srand((unsigned) time(NULL));

    do
    {
        cout << "System szyfrowania danych RSA\n"
                "-----------------------------\n"
                " (C)2012 mgr Jerzy Walaszek\n\n"
                "MENU\n"
                "====\n"
                "[ 0 ] - Koniec pracy programu\n"
                "[ 1 ] - Generowanie kluczy RSA\n"
                "[ 2 ] - Kodowanie RSA\n\n"
                "Jaki jest twoj wybor? ( 0, 1 lub 2 ) : ";
        cin >> w;
        cout << "\n\n\n";
        switch(w)
        {  
        case 1: klucze_RSA( ); break;
        case 2: kodowanie_RSA( ); break;
        }
        cout << "\n\n\n";
    } while( w != 0 );

    return 0;
}