/*** ZADANIE8 *** 1 PKT ***
Mamy klasy AAA, BBB, CCC jak ponizej. W programie nalezy 
napisac kawalek kodu taki, zeby z pomoca wskaznika a dalo
sie wywolac funB(), a z pomoca wskaznika b funC().
Trzeba bedzie cos tez dopisac w klasie AAA, zeby to sie udalo.
***************************/

#include <iostream>

using namespace std;

class AAA {
// tu cos trzeba bedzie dopisac
public:
	virtual void funB() { }
	virtual void funC() { }

};

class BBB : public AAA {
public:
	void funB() { cout << "BBB" << endl; }
};

class CCC : public BBB {
public:
	void funC() { cout << "CCC" << endl; }
};

int main() {
	AAA* a = new BBB;
	AAA* b = new CCC;
// napisz taki kod, zeby z pomoca wskaznikow a i b dalo 
// sie ostatecznie wywolac, odpowiednio, funB() i funC()

	a->funB();
	b->funC();


	delete a;
	delete b;
}

