
#include <iostream>
#include <cmath>

using namespace std;

class TComplex {
private:
    double re{0}, im{0};

public:
    TComplex(double re, double im)
        : re(re), im(im)
    {
    }

    TComplex operator()(double re, double im)
    {
        return TComplex(re, im);
    }

    TComplex operator+(const TComplex& other)
    {
        return TComplex(re + other.re, im + other.im);
    }

    TComplex operator-(const TComplex& other)
    {
        return TComplex(re - other.re, im - other.im);
    }

    friend TComplex conj(const TComplex& other)
    {
        return TComplex(other.re, -other.im);
    }

    friend double abs(const TComplex& other)
    {
        return sqrt(pow(other.re, 2) + pow(other.im, 2));
    }

    TComplex operator*(const TComplex& other)
    {
        return TComplex(re * other.re - im * other.im, re * other.im + im * other.re);
    }

    TComplex operator/(const TComplex& other)
    {
        if (other.re == 0 && other.im == 0) {
            throw invalid_argument("ZeroDivisionError");
        }
        return TComplex((re * other.re + im * other.im) / (pow((other.re), 2) + pow(other.im, 2)), (im * other.re - re * other.im) / (pow((other.re), 2) + pow(other.im, 2)));
    }

    friend ostream& operator<<(ostream& stream, const TComplex& other)
    {
        stream << "(" << other.re << ", " << other.im << ")";
        return stream;
    }

};


int main()
{
    // tworzenie obiektów klasy TComplex
    TComplex obiekt1(2, 3);
    TComplex obiekt2(5.2, -4.5);
    TComplex obiekt3 = obiekt1 + obiekt2;
    TComplex obiekt4 = obiekt2 - obiekt1;

    // wyświetlanie wyników działań na liczbach zespolonych
    cout << "(2, 3) + (5.2, -4.5) = " << obiekt3 << endl;
    cout << "(5.2, -4.5) - (2, 3) = " << obiekt4 << endl;

    cout << "Moduł liczby (2, 3): " << abs(obiekt1) << endl;
    cout << "Sprzężenie liczby (5.2, -4.5): " << conj(obiekt2) << endl;

    cout << "(2, 3) * (5.2, -4.5) = " << obiekt1 * obiekt2 << endl;
    cout << "(2, 3) / (5.2, -4.5) = " << obiekt1 / obiekt2 << endl;

    return 0;
}