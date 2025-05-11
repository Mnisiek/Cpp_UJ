// Napisz program, który zapyta o dwa ciągi znaków oraz je porówna, nie zwracając uwagi na wielkość liter (tzn. żeby traktował literę A i a jako takie same). W tym programie proszę nie używać jeszcze typu std::string, tylko ciągi znaków na początku wpisać do odpowiednio pojemnej tablicy char.

#include <iostream>
#include <cctype>

#define N 100 // maksymalny rozmiar tablicy znakowej

using namespace std;


int main()
{
    int i;
    bool flag = true;
    char c1, c2;
    char str_1[N];
    char str_2[N];

    cout << "Podaj pierwszy ciąg znaków: " << endl;
    cin >> str_1;

    cout << "Podaj drugi ciąg znaków: " << endl;
    cin >> str_2;

    for (i = 0; (flag) && i < N; ++i) { // dopóki nie znaleźliśmy rozróżniającego znaku i nie przekroczyliśmy rozmiaru tablicy
        c1 = str_1[i];
        c2 = str_2[i];
        if (c1 == '\0' || c2 == '\0') { // jeden z napisów się skończył
            break;
        }
        else if (tolower(c1) != tolower(c2)) { // ignorujemy wielkość liter
            flag = false;
        }
    }
    
    if (flag) {
        cout << "Ciągi są identyczne" << endl;
    }
    else {
        cout << "Ciągi są różne" << endl;
    }

    return 0;
}