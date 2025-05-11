#include "klasa.h"
#include <iostream>

using namespace std;

// tu mozna napisac na przyklad definicje operatorow << i >>
// i konstruktora (o ile nie w klasie)


// Liczba::ostream& WyDrukuj(ostream& stream) const; // robią to samo co operatory
// Liczba::istream& OdCzytaj(istream& stream) const;

// Liczba::ostream& operator<<(ostream& stream, const Liczba& ref) {
//     return ref.WyDrukuj(stream);
// }

// std::ostream& operator<<(std::ostream& out, const Liczba& liczba) {
//     out << liczba.WyDrukuj();
//     return out;
// }

// Liczba::istream& operator>>(istream& stream, Liczba& ref) {
//     return ref.OdCzytaj(stream);
// }