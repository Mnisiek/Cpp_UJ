// Napisz program, który wczytuje zdanie, a potem sprawdza, czy jest palindromem (tzn. czytane wspak brzmi tak samo). Przykład: Kobyła ma mały bok. Należy ignorować białe znaki oraz nie zwracać uwagi na wielkość liter.

#include <iostream>
#include <string>
#include <cctype>

using namespace std;


int main()
{
    int i;
    bool flag = true;
    string str;

    cout << "Podaj zdanie do sprawdzenia: ";
    getline(cin, str); // wczytujemy cały ciąg znakowy

    for (i = 0; i < str.length(); ++i) {
        if (! (isalnum(str[i]))) { // jeżeli znak nie jest literą lub cyfrą
            str.erase(i--, 1); // usuwamy go z naszego ciągu
        }
    }

    for (i = 0; (flag) && (i < (str.length() / 2)); ++i) { // sprawdzamy do połowy napisu, idąc indeksami z obu stron
            if (tolower(str[i]) != tolower(str[str.length() -1 -i])) {
                flag = false;
            }
        }

    if (flag) {
        cout << "Zdanie jest palindromem" << endl;
    }
    else {
        cout << "Zdanie nie jest palindromem" << endl;
    }

    return 0;
}