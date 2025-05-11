
#include <iostream>

class TArr {
private:
    struct InnerArray {
        std::size_t len{0};
        std::size_t ref{0};
        int* buf{nullptr};
    } *ptr{nullptr};

public:
    TArr();
    TArr(const TArr& other);
    TArr(TArr&& other);
    TArr& operator=(const TArr& other);
    TArr& operator=(TArr&& other);
    ~TArr();

    // funkcja zmieniająca wartość atrybutu buf
    TArr& change_buf(int new_value)
    {
        if (ptr->ref > 1) {
            // kopiowanie przy zapisie
            InnerArray* new_ptr = new InnerArray;
            new_ptr->len = ptr->len;
            new_ptr->ref = 1;
            new_ptr->buf = new int[ptr->len];
            std::copy(ptr->buf, ptr->buf + ptr->len, new_ptr->buf);
            ptr->ref--;
            ptr = new_ptr;
        }

        ptr->buf[0] = new_value;
        return *this;
    }

    std::size_t get_ref() const {
            return ptr->ref;
        }
};

// konstruktor domyślny
TArr::TArr()
{
    ptr = new InnerArray;
    ptr->ref = 1;
    ptr->len= 0;
    ptr->buf = 0;
}

// konstruktor kopiujący
TArr::TArr(const TArr& other)
{
    other.ptr->ref++;
    this->ptr = other.ptr;
}

// konstruktor przenoszący
TArr::TArr(TArr&& other)
{
    this->ptr = other.ptr;
    other.ptr = nullptr;
}

// operator = kopiujący
TArr& TArr::operator=(const TArr& other)
{
    if (this == &other) {
        return *this;
    }

    other.ptr->ref++;
    if (--ptr->ref == 0) {
        delete[] ptr->buf;
        delete ptr;
    }

    this->ptr = other.ptr;
    return *this;
} 

// operator = przenoszący
TArr& TArr::operator=(TArr&& other)
{
    if (this == &other) {
        return *this;
    }

    if (--ptr->ref == 0) {
        delete[] ptr->buf;
        delete ptr;
    }

    this->ptr = other.ptr;
    other.ptr = nullptr;
    return *this;
}

// destruktor
TArr::~TArr()
{
    if (--ptr->ref == 0) {
        delete[] ptr->buf;
        delete ptr;
    }
}


int main()
{
    TArr array1;
    std::cout << "Liczba referencji array1: " << array1.get_ref() << std::endl;

    TArr array2 = array1;
    std::cout << std::endl << "Liczba referencji array1: " << array1.get_ref() << std::endl;
    std::cout << "Liczba referencji array2: " << array2.get_ref() << std::endl;

    TArr array3;
    array3 = array1;
    std::cout << std::endl << "Liczba referencji array1: " << array1.get_ref() << std::endl;
    std::cout << "Liczba referencji array2: " << array2.get_ref() << std::endl;
    std::cout << "Liczba referencji array3: " << array3.get_ref() << std::endl;

    std::cout << std::endl << "Wywołanie funkcji zmieniającej obiekt array1..." << std::endl;
    array1.change_buf(5);
    std::cout << "Liczba referencji array1: " << array1.get_ref() << std::endl;
    std::cout << "Liczba referencji array2: " << array2.get_ref() << std::endl;
    std::cout << "Liczba referencji array3: " << array3.get_ref() << std::endl;


    return 0;
}