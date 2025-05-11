
#include <iostream>

using namespace std;
 
class A {
private:
    int num;
public:
    void set_num(int number) { num = number; }
    int get_num() { return num; }
};

class B : public virtual A {

};

class C : public virtual A {

};

class D : public B, public C {
    
};


// A program with virtual destructor
 
class Base {
public:
    Base()    
    { cout << "Constructing Base\n"; }
    virtual ~Base()
    { cout << "Destructing Base\n"; }    
};
 
class Derived : public Base {
public:
    Derived()    
    { cout << "Constructing Derived\n"; }
    ~Derived()
    { cout << "Destructing Derived\n"; }
};

 
int main()
{
    Derived* d = new Derived();
    Base* b = d;
    delete b;

    D object;
    object.set_num(5);
    cout << object.get_num() << endl;

    return 0;
}
