
#include <iostream>
#include <memory>

using namespace std;

// Bazowa klasa sterownika wyświetlacza
class DisplayDrv {
public:
    virtual void wykonaj() = 0;
};

// Bazowa klasa sterownika drukarki
class PrinterDrv {
public:
    virtual void wykonaj() = 0;
};

// Bazowa klasa fabryki tworzącej sterowniki
class ResFactory {
public:
    virtual unique_ptr<DisplayDrv> getDispDrv() = 0;
    virtual unique_ptr<PrinterDrv> getPrintDrv() = 0;
};


class LowResDisplayDrv : public DisplayDrv {
public:
    void wykonaj() override
    {
        cout << "Wyświetlanie obrazu niskiej rozdzielczości" << endl;
    }
};


class LowResPrinterDrv : public PrinterDrv {
public:
    void wykonaj() override
    {
        cout << "Drukowanie obrazu niskiej rozdzielczości" << endl;
    }
};


class LowResFactory : public ResFactory {
public:
    unique_ptr<DisplayDrv> getDispDrv() override
    {
        return make_unique<LowResDisplayDrv>();
    }
    
    unique_ptr<PrinterDrv> getPrintDrv() override
    {
        return make_unique<LowResPrinterDrv>();
    }
};



class HighResDisplayDrv : public DisplayDrv {
public:
    void wykonaj() override
    {
        cout << "Wyświetlanie obrazu wysokiej rozdzielczości" << endl;
    }
};


class HighResPrinterDrv : public PrinterDrv {
public:
    void wykonaj() override
    {
        cout << "Drukowanie obrazu wysokiej rozdzielczości" << endl;
    }
};


class HighResFactory : public ResFactory {
public:
    unique_ptr<DisplayDrv> getDispDrv() override
    {
        return make_unique<HighResDisplayDrv>();
    }
    
    unique_ptr<PrinterDrv> getPrintDrv() override
    {
        return make_unique<HighResPrinterDrv>();
    }
};



int main()
{
    // utworzenie fabryki oraz sterowników niskiej rozdzielczości
    unique_ptr<ResFactory> fabryka(new LowResFactory);
    unique_ptr<DisplayDrv> ddrv = fabryka->getDispDrv();
    unique_ptr<PrinterDrv> pdrv = fabryka->getPrintDrv();

    ddrv->wykonaj();
    pdrv->wykonaj();

    // utworzenie fabryki oraz sterowników wysokiej rozdzielczości
    fabryka.reset(new HighResFactory);
    ddrv = fabryka->getDispDrv();
    pdrv = fabryka->getPrintDrv();

    ddrv->wykonaj();
    pdrv->wykonaj();

    return 0;
}

