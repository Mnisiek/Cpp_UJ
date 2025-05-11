// Uzupelnij deifnicje konstruktora klasy A, inicjalizujacego (!!!) skladowa s.
// Napisz definicje operatora konwersji do takiego typu, zeby funkcja fun oraz
// program dzialaly.
// *** 1 pkt ***

#include <iostream>
#include <string>

using namespace std;

class A {
public:
	A(const char* arg) {
		s = arg;
	}; // tu mozna z deklaracji zrobic definicje i dopisac co trzeba

	// operator const char*() const { return s.c_str(); } // czym się różni?
	operator const char*() 
	{
		return s.c_str(); 
	}
	
private:
	std::string s;
};

// ------ ponizej nic nie zmieniamy ------

void fun(char const* ptr) {
	cout << "aaa: " << ptr << endl;
}


int main()
{
	A aaa {"Nalezy zobaczyc ten tekst"};
	fun(aaa);
}

