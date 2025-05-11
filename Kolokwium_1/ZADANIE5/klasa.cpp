#include "klasa.h"

// tu piszemy definicje metod z klasy Litera

Litera::Litera(char c)
{
    lit = c;
}

Litera::Litera(const Litera& c)
{
    lit = c.lit;
}

Litera& Litera::operator=(const Litera& c)
{
    lit = c.lit;
    return *this;
}
