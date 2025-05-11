
#include <iostream>

class A {
private:
    int i;

public:
    A(int n=0)
        : i(n)
    {
    }

    A& operator+()
    {
        return *this; 
    }

    A operator+(const A& other)
    {
        return A(i + other.i);
    }

    A operator-() const
    {
        return A(-i); 
    }

    A operator-(const A& other)
    {
        return A(i - other.i);
    }

    // operator preinkrementacji
    A& operator++()
    {
        ++i;
        return *this; 
    }

    // operator postinkrementacji
    A operator++(int)
    {
        A temp(i);
        ++i;
        return temp;
    }

    // operator predekrementacji
    A& operator--()
    {
        --i;
        return *this;
    }

    // operator postdekrementacji
    A operator--(int)
    {
        A temp(i);
        --i;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& stream, const A& other)
    {
        stream << other.i;
        return stream;
    }

};


int main()
{
    A obiekt1(2);
    A obiekt2(5);

    A obiekt3 = obiekt1 + obiekt2;
    std::cout << "obiekt1 + obiekt2 = " << obiekt3 << std::endl;

    A obiekt4 = obiekt1 - obiekt2;
    std::cout << "obiekt1 - obiekt2 = " << obiekt4 << std::endl;

    std::cout << "obiekt4: " << obiekt4 << ", +obiekt4: " << +obiekt4 << ", -obiekt4: " << -obiekt4 << std::endl;

    // preinkrementacja i predekrementacja działają poprawnie dla wielu znaków ++ albo --
    A obiekt5 = ++++++++++++++++++++++++++++++++obiekt4;
    std::cout << "(32 plusy) ++++++++++++++++++++++++++++++++obiekt4: " << obiekt5 << std::endl;
    std::cout << "(12 minusów) ------------obiekt4: " << ------------obiekt4 << std::endl;

    // postinkrementacja i postdekrementacja nie działają poprawnie dla więcej niż dwóch znaków + albo -
    A obiekt6 = obiekt4----------;
    std::cout << "obiekt6: " << obiekt6 << ", obiekt4----------: " << obiekt4 << std::endl;
    A obiekt7 = obiekt4++++++++++++++++;
    std::cout << "obiekt7: " << obiekt7 << ", obiekt4++++++++++++++++: " << obiekt4 << std::endl;
    

    return 0;
}
