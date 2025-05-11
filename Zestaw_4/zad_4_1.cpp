
#include <iostream>
#include <string>
#include <compare>

using namespace std;

class TKlasa {
private:
    string str;

public:
    TKlasa(const char* c)
        : str(c)
    {
    }

    // operator [] sprawdza, czy podany ciąg znajduje się w obiekcie klasy TKlasa
    const char* operator[](const char* s) const 
    {
        auto starting_position = str.find(s);
        if (starting_position != string::npos) {
            return str.c_str() + starting_position;
        }
        else {
            return nullptr;
        }
    }

    // przeciążenie operatora porównania <=>
    auto operator<=>(const TKlasa& other) const {
        return str <=> other.str;
    }
};

int main()
{
    TKlasa klasa1("ala ma kota");
    TKlasa klasa2("dom z cegły");
    const char* napis1 = "kot";

    // szukamy pierwszego wystąpienia podciągu napis1
    cout << klasa1[napis1] << endl;

    // cout << klasa2[napis1] << endl;

    // działanie operatorów porównania dla obiektów typu TKlasa
    auto result = klasa1 <=> klasa2;
    if (result == std::strong_ordering::less) {
        cout << "klasa1 < klasa2" << endl;
    }
    else if (result == std::strong_ordering::greater) {
        cout << "klasa1 > klasa2" << endl;
    }
    else {
        cout << "klasa1 == klasa2" << endl;
    }

    return 0;
}
