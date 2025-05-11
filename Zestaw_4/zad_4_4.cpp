
#include <iostream>

class A {
private:
    int value;
public:
    A()
        : value(0)
    {
    }

    A(int num)
        : value(num)
    {
    }

    void funA()
    {
        std::cout << "Wartość:" << value << std::endl;
    }
};

class TSmartPtr {
private:
    A *fp {nullptr};
    A* fTable[5] {nullptr};
    int fUse {0};

public:
    TSmartPtr(A *prt = nullptr)
        : fp(prt)
    {
    }

    A* operator->()
    {
        fTable[fUse] = fp;
        fUse = (++fUse) % 5;
        return fp;
    }

    A& operator*()
    {
        return *(operator->());
    }

    // preinkrementacja
    TSmartPtr& operator++()
    {
        ++fp;
        return *this;
    }

    // predekrementacja
    TSmartPtr& operator--()
    {
        --fp;
        return *this;
    }
};


int main()
{
    A a;
    TSmartPtr wsk = &a; // konstruktor TSmartPtr
    wsk->funA(); // tu działa przeciążony operator ->
    // przy okazji zapisuje sobie w wewnętrznej tablicy fakt użycia
    (*wsk).funA(); // tak też powinno się dać, zawsze przeciążajmy parami

    // smart_ptr wskazuje na początek tablicy o elementach typu A
    A tablica[] = {2, 5, 7, -4};
    TSmartPtr smart_ptr = tablica;
    // pierwszy element tablicy
    smart_ptr->funA();

    // dwukrotna preinkrementacja i działanie operatora ->
    (++++smart_ptr)->funA();

    return 0;
}