
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
	Obserwator(const char* s) : nazwa{s ? s : "nienazwany"} { /* nic nie robi */ }
	virtual ~Obserwator() { } // klasa bazowa
	virtual void update() = 0; // metoda czysto wirtualna
	const char* id() const { return nazwa.c_str(); }
private:
	string nazwa;
};

class Manager {
public:
	void dodaj(Obserwator* p);
	void usun(Obserwator* p);
	void powiadom();
	void obserwatorzy() const;
private:
	list<Obserwator*> klient;
};

void Manager::obserwatorzy() const {
	if (klient.empty()) cout << "Brak obserwatorow\n";
	auto it = klient.cbegin();
	while (it != klient.cend()) {
		cout << "Obserwator " << (*it)->id() << endl;
		++it;
	}
}

void Manager::powiadom() {
	for (auto& p : klient) p->update();
}

void Manager::dodaj(Obserwator* p) {
    if ( find(klient.begin(),klient.end(), p) == klient.end() ) {
        klient.push_back(p);
    } else {
        cout << "Obserwator " << p->id() << " jest juz na liscie\n";
    }
}

void Manager::usun(Obserwator* p) {
	klient.erase( find(klient.begin(),klient.end(), p) );
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
	//return static_cast<double>( rand() % (int)(b - a + 1) + a );
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
	Monitor(const char* s, const Meteo& r) : Obserwator(s), ref(r) { }
	virtual void update() override final {
		t = ref.getT();
		cout << "Obserwator " << id() << " t = " << t << endl;
	}
private:
	double t {0.};
	const Meteo& ref;
};

class MonitorSredni : public Obserwator {
public:
	MonitorSredni(const char* s, const Meteo& r) : Obserwator(s), ref(r) { }
	void update() {
		vec.push_back(ref.getT());
		tsr = 0.;
		for (const auto& d : vec) tsr += d;
		tsr /= vec.size();
		cout << "Obserwator " << id() << " t srednia = " << tsr << endl;
	}
private:
	double tsr {0.};
	vector<double> vec;
	const Meteo& ref;
};

auto main() -> int {
	Meteo stacja;
	Obserwator* p1 = new Monitor("Monitor 1",stacja);
	Obserwator* p2 = new Monitor("Monitor 2",stacja);
	Obserwator* p3 = new MonitorSredni("Monitor Sredni 1",stacja);
	Obserwator* p4 = new MonitorSredni("Monitor Sredni 2",stacja);
	stacja.obserwatorzy(); // pusta lista
	stacja.dodaj(p1);
	stacja.dodaj(p2);
	stacja.dodaj(p3);
	stacja.dodaj(p4);
	stacja.obserwatorzy(); // lista nazw wszystkich podlaczonych obserwatorow
	stacja(2); // dwa losowania, stacja.operator()(2);
	stacja.dodaj(p1); // sprawdzenie, czy p1 jest juz na liscie
	stacja.usun(p3); // od teraz p3 nie jest obserwatorem
	stacja(10);
	delete p1;
	delete p2;
	delete p3;
	delete p4;
}
