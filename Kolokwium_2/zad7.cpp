/*** ZADANIE 7 *** 2 PKT ***
1) napisz operator>> wczytujacy ze strumienia slowa (string) 
do obiektow struktury MyString, ale zamieniajac w locie litery w slowach na wielkie.
2) za pomoca algorytmu copy oraz iteratora strumienia wejsciowego
wczytac zawartosc pliku do wektora vs
3) wypisac zawartosc vs w dowolny sposob
****************************/

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

struct MyString {
    string str;

    friend istream& operator>>(istream& is, MyString& mystring)
    {
        is >> mystring.str;

        // zamiana liter na wielkie
        transform(mystring.str.begin(), mystring.str.end(), mystring.str.begin(), ::toupper);

        return is;
    }
};



int main() {
    vector<MyString> vs;
    ifstream plik("test.txt"); // utworz jakis plik test.txt

    if (!plik) {
        cout << "Błąd przy otwarciu pliku" << endl;
        return -1;
    }

    copy(istream_iterator<MyString>(plik), istream_iterator<MyString>(), back_inserter(vs)); 

    for (auto element: vs) {
        cout << element.str << endl;
    }

    plik.close();
}