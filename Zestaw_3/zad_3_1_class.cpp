#include "zad_3_1.h"
#include <iostream>

using namespace std;
// #define DEBUG


MyString::MyString()
{
    m_napis = "***";

    #ifdef DEBUG
        cout << "Konstruktor bezargumentowy" << endl;
    #endif
}

MyString::MyString(string &s)
{
    m_napis = s;

    #ifdef DEBUG
        cout << "Konstruktor z argumentem string" << endl;
    #endif
}

MyString::MyString(const char *s)
{
    m_napis = s;

    #ifdef DEBUG
        cout << "Konstruktor z argumentem const char*" << endl;
    #endif
 }

MyString::MyString(const MyString& s)
{
    m_napis = s.m_napis;

    #ifdef DEBUG
        cout << "Konstruktor kopiujący" << endl;
    #endif
}

MyString::MyString(MyString&& s)
{
    if (this != &s) {
        m_napis = s.m_napis;
        s.m_napis.erase();
    }

    #ifdef DEBUG
        cout << "Konstruktor przenoszący" << endl;
    #endif
}


MyString &MyString::operator=(const MyString& s)
{
    m_napis = s.m_napis;
    return *this;

    #ifdef DEBUG
        cout << "Operator kopiujący" << endl;
    #endif
}

MyString MyString::operator=(MyString&& s)
{
    if (this != &s) {
        m_napis = s.m_napis;
        s.m_napis.erase();
    }
    return *this;

    #ifdef DEBUG
        cout << "Operator przenoszący" << endl;
    #endif

}

void MyString::Print()
{
    cout << m_napis << endl;
    #ifdef DEBUG
        cout << "Wypisywanie" << endl;
    #endif
}

MyString::~MyString()
{
    #ifdef DEBUG
        cout << "Destruktor" << endl;
    #endif
}