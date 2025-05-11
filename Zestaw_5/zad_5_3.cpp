
#include <iostream>
#include <string>

using namespace std;


class MozeWykBadania {
public:
    void badaj()
    {
        cout << "Może wykonywać badania naukowe" << endl;
    }
};

class MozeNauczac {
public:
    void nauczaj()
    {
        cout << "Może nauczać studentów" << endl;
    }
};

class TOsoba {
private:
    string m_imie;
    string m_nazwisko;
public:
    TOsoba() : m_imie("Brak danych"), m_nazwisko("Brak danych") {}
    TOsoba(const string& imie, const string& nazwisko) : m_imie(imie), m_nazwisko(nazwisko) {}

    void dane_osobowe()
    {
        cout << "Imię: " << m_imie << ", nazwisko: " << m_nazwisko << endl;
    }
};

class MozeBycStudentem {
public:
    void studiuj()
    {
        cout << "Może studiować" << endl;
    }

};

class TAsystentBadan : public virtual TOsoba, public MozeWykBadania {
public:
    TAsystentBadan(const string& imie, const string& nazwisko) : TOsoba(imie, nazwisko) {}

    void asystent_badan()
    {
        cout << "Jest asystentem badań" << endl;
    }
};

class TStudent : public virtual TOsoba, public MozeBycStudentem {
public:
    TStudent(const string& imie, const string& nazwisko) : TOsoba(imie, nazwisko) {}

    void student()
    {
        cout << "Jest studentem" << endl;
    }
};

class TDoktorant : public TStudent {
public:
    TDoktorant(const string& imie, const string& nazwisko) : TStudent(imie, nazwisko) {}
    void doktorant()
    {
        cout << "Jest doktorantem" << endl;
    }
};

class TDoktorantBadacz : public TAsystentBadan, public TDoktorant {
public:
    TDoktorantBadacz(const string& imie, const string& nazwisko) 
        : TAsystentBadan(imie, nazwisko), TDoktorant(imie, nazwisko), TOsoba(imie, nazwisko) {}

    void doktorant_badacz()
    {
        cout << "Jest doktorantem i wykonuje badania" << endl;
    }
};


class TDoktorantNaucz : public TDoktorant, public MozeNauczac {
public:
    TDoktorantNaucz(const string& imie, const string& nazwisko) : TDoktorant(imie, nazwisko), TOsoba(imie, nazwisko) {}

    void doktorant_naucz()
    {
        cout << "Jest doktorantem i naucza studentów" << endl;
    }
};


int main()
{
    // utworzenie obiektów klas pochodnych i wywołanie różnych metod
    TAsystentBadan asystent1("Marcin", "Urbański");
    asystent1.dane_osobowe();
    asystent1.asystent_badan();
    asystent1.badaj();
    cout << endl;

    TStudent student1("Adam", "Górski");
    student1.dane_osobowe();
    student1.student();
    student1.studiuj();
    cout << endl;

    TDoktorant doktorant1("Anna", "Grzyb");
    doktorant1.dane_osobowe();
    doktorant1.doktorant();
    doktorant1.student();
    doktorant1.studiuj();
    cout << endl;

    TDoktorantBadacz doktorant_badacz1("Jadwiga", "Skowronek");
    doktorant_badacz1.dane_osobowe();
    doktorant_badacz1.doktorant_badacz();
    doktorant_badacz1.badaj();
    doktorant_badacz1.studiuj();
    cout << endl;

    TDoktorantNaucz doktorant_naucz1("Szymon", "Leśny");
    doktorant_naucz1.dane_osobowe();
    doktorant_naucz1.doktorant_naucz();
    doktorant_naucz1.nauczaj();
    doktorant_naucz1.studiuj();
    cout << endl;

    return 0;
}

