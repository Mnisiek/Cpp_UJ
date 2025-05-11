
#include "zad_3_1.h"
#include <iostream>

using namespace std;


int main()
{
    MyString a; // wywołuje konstruktor bezparametrowy
    MyString b{"ala ma kota"}; // wywołuje konstruktor const char*
    MyString c(b);

    a.Print();
    b.Print();
    c.Print();

    c = "napis"; // wywołuje operator przypisania przenoszący
    a = c; // wywołuje operator przypisania kopiujący

    a.Print();
    c.Print();

}
