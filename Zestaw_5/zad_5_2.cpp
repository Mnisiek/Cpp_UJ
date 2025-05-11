
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

class Obserwator {
public:
    Obserwator(const string& s) : id(s) {}
    virtual ~Obserwator() = default;
    virtual void update() = 0; // metoda czysto wirtualna
    const string& getId() const { return id; }
private:
    string id;
};


class Manager {
public:
    void dodaj(unique_ptr<Obserwator>&& o);
    void usun(const string& id);
    void powiadom();
    void obserwatorzy() const;
private:
    list<unique_ptr<Obserwator>> klient;
};

void Manager::obserwatorzy() const {
    if (klient.empty()) cout << "Brak obserwatorow\n";

    auto it = klient.cbegin();
	while (it != klient.cend()) {
		cout << "Obserwator " << (*it)->getId() << endl;
		++it;
	}
}

void Manager::powiadom() {
    for (auto& p : klient) p->update();
}

void Manager::dodaj(unique_ptr<Obserwator>&& o) {
    // wykorzystujemy wyrażenie lambda do sprawdzenia, czy
    // nazwy obserwatorów są takie same
    auto it = find_if(klient.begin(), klient.end(), 
    [&o](const unique_ptr<Obserwator>& op) {
        return (op->getId() == o->getId());
    });

    if (it != klient.end()) {
        cout << "Obserwator " << o->getId() << " jest już na liście\n";
    } else {
        klient.push_back(move(o));
    }
}

void Manager::usun(const string& id) {
    // podobnie jak w funkcji dodaj, szukamy czy element
    // o podanej nazwie jest już na liście
    auto it = find_if(klient.begin(), klient.end(),
    [&id](const unique_ptr<Obserwator>& op) {
        return (op->getId() == id);
    });

    if (it != klient.end()) {
        klient.erase(it);
    }
}

class Meteo : public Manager {
public:
    double getT() const { return t; }
    void operator()(size_t n);
private:
    double t {0.};
    double losuj(double a, double b);
    random_device rd;
};

double Meteo::losuj(double a, double b) {
    mt19937 gen(rd());
    uniform_real_distribution<> dis(a,b);
    return dis(gen);
}

void Meteo::operator()(size_t n) {
    while (n--) {
        t = losuj(5,25);
        powiadom();
    }
}

class Monitor : public Obserwator {
public:
    Monitor(const string& s, const Meteo& r) : Obserwator(s), ref(r) { }
    virtual void update() override final {
        t = ref.getT();
        cout << "Obserwator " << getId() << " t = " << t << endl;
    }
private:
    double t {0.};
    const Meteo& ref;
};

class MonitorSredni : public Obserwator {
public:
    MonitorSredni(const string& s, const Meteo& r) : Obserwator(s), ref(r) { }
    void update() {
        vec.push_back(ref.getT());
        tsr = 0.;
        for (const auto& d : vec) tsr += d;
        tsr /= vec.size();
        cout << "Obserwator " << getId() << " t srednia = " << tsr << endl;
    }
private:
    double tsr {0.};
    vector<double> vec;
    const Meteo& ref;
};

int main() {
    Meteo stacja;
    auto p1 = make_unique<Monitor>("Monitor 1", stacja);
    auto p2 = make_unique<Monitor>("Monitor 2", stacja);
    auto p3 = make_unique<MonitorSredni>("Monitor Sredni 1", stacja);
    auto p4 = make_unique<MonitorSredni>("Monitor Sredni 2", stacja);
    stacja.dodaj(move(p1));
    stacja.dodaj(move(p2));
    stacja.dodaj(move(p3));
    stacja.dodaj(move(p4));
    stacja.obserwatorzy();
    stacja(2);

    // trzeba tak zrobić, bo po wykonaniu stacja.dodaj(move(p1)); wskaźnik p1
    // zostaje zniszczony (dlatego tworzymy nowy wskaźnik o tej samej nazwie),
    // co pozwala zobaczyć komunikat, że taki element jest już na liście
    auto p1_copy = make_unique<Monitor>("Monitor 1", stacja);
    stacja.dodaj(move(p1_copy));

    stacja.usun("Monitor Sredni 1");
    stacja(100);

    return 0;
}

