/*
Napisz program konwertujący zadaną liczbę arabską z przedziału 0 .. 3999, podaną jako parametr wejściowy na liczbę w zapisie rzymskim. Sprawdzać poprawność podanego parametru. Poprzez „parametr wejściowy” rozumiem podanie liczby w linii wywołania programu, czyli np.: prog.exe 2023
*/

#include <iostream>
#include <string>

#define L (sizeof(rz) / sizeof(rz[0])) // liczba elementów w tablicy rz[]

using namespace std;

 // struktura zawierająca liczbę arabską i odpowiadającą jej liczbę rzymską
struct RZYM {
    int arab;
    string rzym;
};

int main(int argc, char* argv[])
{
    struct RZYM rz[]={{1,"I"}, {4,"IV"}, {5,"V"}, {9,"IX"}, {10,"X"},
    {40,"XL"},{50,"L"}, {90,"XC"}, {100,"C"}, {400,"CD"}, {500,"D"},
    {900,"CM"}, {1000,"M"}};
    unsigned int arab_number;
    int i;
    string result;

    // obsługa błędów wywołania programu
	if (argc == 1) {
		cout << "Nie podano liczby arabskiej do konwersji. Program przyjmuje argument wywolania w postaci: ./nazwa_programu liczba_arabska" << endl;
        return 0;
	}
	else if (argc > 2) {
		cout << "Podano za duzo argumentow. Program przyjmuje jeden argument wywolania w postaci: ./nazwa_programu liczba_arabska" << endl;
        return 0;
    }

    arab_number = stoi(argv[1]); // zamiana napisu na liczbę całkowitą
    if (arab_number < 0 || arab_number > 3999) {
        cout << "Podana liczba nie miesci sie w dopuszczalnym zakresie "
        "0 .. 3999. Podaj liczbe z zakresu, aby program zadzialal poprawnie." << endl;
        return 0;
    }

    // algorytm zamiany liczby arabskiej na rzymską
    for (i = L - 1; i >= 0 && arab_number > 0; i--) {
        while (arab_number >= rz[i].arab) {
            result += rz[i].rzym;
            arab_number -= rz[i].arab;
        }
    }

    // wypisanie wyniku
    cout << "Liczba po konwersji: " << result << endl;

    return 0;
}
