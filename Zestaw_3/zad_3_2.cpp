
#include <iostream>
#include <string>


class BigInt
{
private:
    std::string m_number;

public:
    BigInt();
    BigInt(const std::string& number);

    BigInt& operator=(const BigInt& other);
    void print();

    BigInt add(const BigInt& other);
    BigInt subtract(const BigInt& other);
};

BigInt::BigInt()
    {
        m_number = "0";
    }

BigInt::BigInt(const std::string& number)
    {
        m_number = number;
    }

BigInt& BigInt::operator=(const BigInt& other) {
        if (this != &other) {
            m_number = other.m_number;
        }
        return *this;
    }

void BigInt::print()
    {
        std::cout << m_number << std::endl;
    }

BigInt BigInt::add(const BigInt& other)
    {
        int extra_number, i, j;
        int k;
        extra_number = 0;

        // ostatni index to długość napisu - 1
        i = m_number.length() - 1;
        j = other.m_number.length() - 1;
        if (i > j) {
            k = i + 1;
        } else {
            k = j + 1;
        }
        std::string result(k + 1, '0');

        // dopóki jest co dodawać (czyli nie skończyła się nam pierwsza lub druga liczba lub jest niezerowe przeniesienie)
        while (i >= 0 || j >= 0 || extra_number > 0) {
            int sum_result = extra_number;
            if (i >= 0) {
                sum_result += m_number[i] - '0';
                i--;
            }
            if (j >= 0) {
                sum_result += other.m_number[j] - '0';
                j--;
            }
            extra_number = sum_result / 10;

            result[k] = '0' + (sum_result % 10);
            k--;
        }

        // usunięcie wiodących zer
        std::string result_without_0;
        for (k = 0; k < result.length(); ++k) {
            if (result[k] != '0') {
                break;
            }
        }
        if (k == result.length()) {
            result_without_0 = "0";
        }
        for ( ; k < result.length(); ++k) {
            result_without_0 += result[k];
        }

        return BigInt(result_without_0);
    }

BigInt BigInt::subtract(const BigInt& other)
    {
        int borrow, i, j;
        int k;
        borrow = 0;

        // ostatni index to długość napisu - 1
        i = m_number.length() - 1;
        j = other.m_number.length() - 1;

        if (i > j) {
            k = i + 1;
        } else {
            k = j + 1;
        }
        std::string result(k + 1, '0');

        // dopóki jest co odejmować (czyli nie skończyła się nam pierwsza lub druga liczba)
        while (i >= 0 || j >= 0) {
            int difference = borrow;
            if (i >= 0) {
                difference += (m_number[i] - '0');
                i--;
            }
            if (j >= 0) {
                difference -= (other.m_number[j] - '0');
                j--;
            }
            if (difference < 0) {
                difference += 10;
                borrow = -1;
            } else {
                borrow = 0;
            }
            result[k] = '0' + difference;
            k--;
        }

        // usunięcie wiodących zer
        std::string result_without_0;
        for (k = 0; k < result.length(); ++k) {
            if (result[k] != '0') {
                break;
            }
        }
        if (k == result.length()) {
            result_without_0 = "0";
        }
        for ( ; k < result.length(); ++k) {
            result_without_0 += result[k];
        }

        return BigInt(result_without_0);
    }


int main()
{
    std::string number1;
    std::string number2;
    char operation;

    BigInt a;
    BigInt b;
    BigInt result;

    std::cout << "Podaj pierwszą liczbę: " << std::endl;
    std::cin >> number1;

    std::cout << "Podaj drugą liczbę: " << std::endl;
    std::cin >> number2;

    std::cout << "Podaj operację: " << std::endl;
    std::cin >> operation;

    // konstrukcja obiektów a i b typu BigInt
    a = BigInt(number1);
    b = BigInt(number2);

    if (operation == '+') {
        result = a.add(b);
    }

    if (operation == '-') {
        result = a.subtract(b);
    }

    std::cout << "Wynik operacji " << operation << " :" << std::endl;
    result.print();

    return 0;
}