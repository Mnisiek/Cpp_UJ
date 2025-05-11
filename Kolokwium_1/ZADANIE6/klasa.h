#include <iostream>


// To jest definicja klasy. Prosze napisac konieczne deklaracje.
// Definicje funkcji umiescic w pliku klasa.cpp

class Liczba {
   public:
   // Uwaga!!! prosze napisac tylko JEDEN konstruktor
   // INICJALIZUJACY skladowa n jak ponizej
   // oraz przeciazyc operatory << i >>	
	
   Liczba() = default;
   Liczba(int num)
   {
      n = num;
   }

   friend std::ostream& operator<<(std::ostream stream, const Liczba& ref)
   {
      stream << ref.n;
      return stream;
   }

   friend std::istream& operator>>(std::istream stream, Liczba& ref)
   {
      stream >> ref.n;
      return stream;
   }

   // ostream& WyDrukuj(ostream& stream) const;
   // istream& OdCzytaj(istream& stream) const;
   // std::ostream& operator<<(std::ostream& stream, const Liczba& ref);
   // std::istream& operator>>(std::istream& stream, Liczba& ref);

	private:
          int n;
};

