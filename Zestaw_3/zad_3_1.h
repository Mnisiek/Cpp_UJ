#ifndef MY_STRING_H
#define MY_STRING_H

#include <string>

class MyString
{
private:
    std::string m_napis;

public:
    MyString(); // konstruktor bezargumentowy
    MyString(std::string& s);
    MyString(const char* s);
    MyString(const MyString& s); // konstruktor kopiujący
    MyString(MyString&& s); // konstruktor przenoszący


    MyString& operator=(const MyString& s); // operator kopiujący
    MyString operator=(MyString&& s); // operator przenoszący

    void Print();

    ~MyString(); // destruktor
};

#endif