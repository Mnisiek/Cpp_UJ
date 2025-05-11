// #include <iostream>
// #include <string>
// #include <cstring> // memset

// #define N 10

// void Increment(int* value) // wskaźnik na zmienną int
// {
//     (*value)++; // inkrementacja wartości wyłuskanej ze wskaźnika
// }

// void Increment(int& value) // referencja do zmiennej int
// {
//     value++; // inkrementacja wartości przekazanej przez referecję
// }

// int main()
// {
//     char* buffer = new char[N]; // wkaźnika na pierwszy element tablicy zaalokowanej na stercie (heap)
//     memset(buffer, 5, N);

//     char arr[N];
//     char** ptr = &buffer; // wzkaźnik na wskaźnik

//     memcpy(arr, *ptr, N);

//     delete[] buffer; // usunięcie tablicy

//     int a = 10;
//     int& b = a;

//     b = 5;

//     Increment(&a); // to samo działanie
//     Increment(b);

//     return 0;
// }

#include <stdio.h>
#define MAXLINE 1000 // dopuszczalna długość wiersza

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // wzorzec do wyszukiwania

// wyszukuje wszystkie wiersze zawierające wzorzec
int main()
{
    char line[MAXLINE];
    int found = 0;

    while (my_getline(line, MAXLINE) > 0) {
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
    }

    return found;
}

// my_getline: pobiera wiersz do s, zwraca długość
int my_getline(char s[], int lim)
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '@' && c != '\n') {
        s[i++] = c;
    }
    if (c == '\n') {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

// strindex: zwraca index t w s lub -1, jeżeli nie występuje
// zmodyfikowana wersja — zwraca ostatnie wystąpienie wzorca
int strindex(char s[], char t[])
{
    int i, j, k;
    int last_found = -1;

    for (i = 0; s[i] != '\0'; ++i) {
        for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; ++j, ++k) {
            ;
        }
        if (k > 0 && t[k] == '\0') {
            last_found = i;
        }
    }
    printf("%d\n", last_found);
    return last_found;
}