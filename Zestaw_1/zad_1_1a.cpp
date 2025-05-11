// Napisz program, który narysuje kwadrat o zadanym boku (liczbie gwiazdek) oraz pusty w środku (też o zadanym boku). O parametry zapytaj w programie, sprawdzając ich poprawność.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int i, length;
    int outer_size, inner_size;

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
    for (i = 0; i < length; ++i) {
        cout << setfill('*') << setw(outer_size) << "\n"; // górna część wypełnionego kwadratu
    }

    for (i = 0; i < inner_size; ++i) {
        cout << setfill('*') << setw(length) << ""; // lewa ramka
        cout << setfill(' ') << setw(inner_size) << ""; // pusty środek kwadratu
        cout << setfill('*') << setw(outer_size - inner_size - length) << "\n"; // prawa ramka
    }

    for (i = 0; i < length; ++i) {
        cout << setfill('*') << setw(outer_size) << "\n"; // dolna część wypełnionego kwadratu
    }
    
    return 0;

}
