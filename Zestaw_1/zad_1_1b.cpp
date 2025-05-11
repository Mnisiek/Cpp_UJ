#include <iostream>
#include <format>
#include <string>

using namespace std;


int main()
{
    int i, length;
    int outer_size, inner_size;
    string str(inner_size, ' ');

    cout << "Podaj dlugosc boku zapełnionego kwadratu: ";
    cin >> outer_size;
    
    if (outer_size < 0) {
        cout << "Długość boku musi być liczbą dodatnią" << endl;;
        return 1;
    }
    
    cout << "Podaj dlugosc boku kwadratu pustego w środku: ";
    cin >> inner_size;
    
    if (inner_size < 0 || inner_size > outer_size) {
        cout << "Długość boku wewnętrznego kwadratu musi być dodatnia i  mniejsza od długości boku zewnętrznego kwadratu" << endl;
        return 1;
    }
    
    length = (outer_size - inner_size) / 2; // rozmiar 'ramki' kwadratu

    // nie wiem, jak przekazać do funkcji format() rozmiar zewnętrznego kwadratu, więc ustawiłem w tym przypadku jego wymiar na sztywno na 16
	for (i = 0; i < outer_size; ++i) {
        if ((i < length) || (i > inner_size + length + 1)) {
            cout << format("{:*^16}\n", "*"); // wypełnienie gwiazdkami
        }
        else {
            cout << format("{:*^16}\n", str); // wypełnienie spacjami
        }

    }

    return 0;
}