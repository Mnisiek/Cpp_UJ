
#include <iostream>

using namespace std;

class DP {
public:
    // metody czysto wirtualne
    virtual void draw_line() = 0;
    virtual void draw_circle() = 0;
};

class DP1: public DP {
public:
    // implementacja rysowania prostokąta i koła z wykorzystaniem biblioteki DP1
    void draw_line() override {
        cout << "Rysowanie prostokąta z wykorzystaniem biblioteki DP1" << endl;
    }

    void draw_circle() override {
        cout << "Rysownie koła z wykorzystaniem biblioteki DP1" << endl;
    }
};

class DP2: public DP {
public:
    // implementacja rysowania prostokąta i koła z wykorzystaniem biblioteki DP2
    void draw_line() override {
        cout << "Rysownie prostokąta z wykorzystaniem biblioteki DP2" << endl;
    }

    void draw_circle() override {
        cout << "Rysownie koła z wykorzystaniem biblioteki DP2" << endl;
    }
};

class Drawing {
protected:
    DP* library;
public:
    explicit Drawing(DP* lib) : library(lib) {}
    virtual void draw() = 0; // metoda czysto wirtualna
    
    void setLib(DP* lib) {
        library = lib;
    }
    
    DP* getLib() const {
        return library;
    }
};

class V1Drawing: public Drawing {
public:
    explicit V1Drawing(DP& d) : Drawing(&d) {}

    // metoda draw() z klasy Drawing zostaje nadpisana
    void draw() override {
        library->draw_line();
    }
};

class V2Drawing: public Drawing {
public:
    explicit V2Drawing(DP& d) : Drawing(&d) {}

    // metoda draw() z klasy Drawing zostaje nadpisana
    void draw() override {
        library->draw_circle();
    }
};

class Shape {
protected:
    Drawing* drawing;
public:
    explicit Shape(Drawing* d) : drawing(d) {}
    virtual void draw() = 0; // metoda czysto wirtualna

    void setLib(Drawing* d) {
        drawing->setLib(d->getLib());
    }
};

class Rectangle: public Shape {
public:
    explicit Rectangle(Drawing* d) : Shape(d) {}

    // metoda draw() z klasy Shape zostaje nadpisana
    void draw() override {
        drawing->draw();
    }
};

class Circle: public Shape {
public:
    explicit Circle(Drawing* d) : Shape(d) {}

    // metoda draw() z klasy Shape zostaje nadpisana
    void draw() override {
        drawing->draw();
    }
};


int main() 
{
    DP1 library1; 
    DP2 library2; 
    Drawing *d1 = new V1Drawing(library1);
    Drawing *d2 = new V2Drawing(library2);
    Shape *p1 = new Rectangle(d1);
    Shape *p2 = new Circle(d2);

    p1->draw(); 
    p2->draw(); 

    p1->setLib(d2);
    p2->setLib(d1);

    p1->draw(); 
    p2->draw(); 

    delete p1;
    delete p2;
    delete d1;
    delete d2;

    return 0;
}

