
#include <iostream>

using namespace std;

#define P(x) std::cout << x << std::endl

class A1 {
private:
    int i { 5 };
public:
    A1(bool) { P("A1 c-tor"); }
    virtual ~A1() { P("A1 d-tor"); }
    int get() const { return i; }
};

class V1 : virtual public A1 {
public:
    V1(bool) : A1(true) { P("V1 c-tor"); }
    virtual ~V1() override { P("V1 d-tor"); }
};

class C1 : virtual public V1 {
public:
    C1(bool) : A1(true), V1(true) { P("C1 c-tor"); }
    virtual ~C1() override { P("C1 d-tor"); }
};

class B2 {
public:
    B2(bool) { P("B2 c-tor"); }
    virtual ~B2() { P("B2 d-tor"); }
};

class B3 {
public:
    B3(bool) { P("B3 c-tor"); }
    virtual ~B3() { P("B3 d-tor"); }
};

class V2 : virtual public A1, public B2 {
public:
    V2(bool) : A1(true), B2(true) { P("V2 c-tor"); }
    virtual ~V2() override { P("V2 d-tor"); }
};

class C2 : virtual public V2, public B3 {
public:
    C2(bool) : A1(true), V2(true), B3(true) { P("C2 c-tor"); }
    virtual ~C2() override { P("C2 d-tor"); }
};

class M1 {
public:
    M1(bool) { P("M1 c-tor"); }
    virtual ~M1() { P("M1 d-tor"); }
};

class M2 {
public:
    M2(bool) { P("M2 c-tor"); }
    virtual ~M2() {P("M2 d-tor"); }
};

class X : public C1, public C2 {
private:
    M1 m1;
    M2 m2;
public:
    X(bool) : A1(true), V1(true), C1(true), V2(true), C2(true), m1(true), m2(true) { P("X c-tor"); }
    virtual ~X() override { P("X d-tor"); }
};


int main()
{
    A1* pa = new X(true);
    cout << pa->get() << endl; // zakomentować gdy public A1
    delete pa;
}

/*
Odpowiedzi na pytania: 
a) co się stanie jeśli virtual ~V1(); (i inne, bez override) i ~A1(); (niewirtualne).
Odpowiedź: Konstruktory wywołały się w tej samej kolejności, natomiast
pierwszy został wywołany destruktor klasy A1, co spowodowało przerwanie
działania programu:
free(): invalid size
Przerwanie (zrzut pamięci)

b) co się stanie jeśli będzie dziedziczenie zwykłe public A.
Odpowiedź: Konstruktory i destruktory zostaną wywołane w innej kolejności;
może to prowadzić do błędów w wykonaniu programu.
*/

