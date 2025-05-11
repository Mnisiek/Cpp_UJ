#include <iostream>

// To jest definicja klasy oraz deklaracje, ktorych 
// definicje nalezy umiescic w pliku klasa.cpp

class Litera {
   public:
	Litera(char c);
	Litera(const Litera& c);
	Litera& operator=(const Litera& c);
	
	char print() const { return lit; }
	
   private:
     char lit;
};

