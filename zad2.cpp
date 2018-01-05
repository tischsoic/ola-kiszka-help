#include <iostream>
#include <fstream>

using namespace std;

struct EListy {
    float klucz;
    EListy *nast = nullptr;
};

class Zbior {
    EListy *poczatek;

public:
    Zbior(): poczatek(nullptr) {}

    void dodajNaKoncu(float klucz) {
        EListy *nowyEl = new EListy();
        nowyEl->klucz = klucz;

        if (this->poczatek == nullptr) {
            this->poczatek = nowyEl;
            return;
        }

        EListy *ostatni = this->poczatek;
        while (ostatni->nast != nullptr) {
            ostatni = ostatni->nast;
        }

        ostatni->nast = nowyEl;
    }

    void DodajElem(float klucz) {
        EListy *nowyEl = new EListy();
        nowyEl->klucz = klucz;

        if (this->poczatek == nullptr) {
            this->poczatek = nowyEl;
            return;
        }

        EListy *obecny = this->poczatek,
                *poprzedni = nullptr;
        while (obecny != nullptr) {
            if (obecny->klucz == klucz) {
                return;
            }
            poprzedni = obecny;
            obecny = obecny->nast;
        }

        poprzedni->nast = nowyEl;
    }

    friend ostream &operator<<(ostream &output, const Zbior &z) {
        EListy *obecny = z.poczatek;
        while (obecny != nullptr) {
            output << obecny->klucz << " ";
            obecny = obecny->nast;
        }

        return output;
    }

    friend Zbior operator+(const Zbior &z1, const Zbior &z2) {
        Zbior calosc;

        EListy *obecny = z1.poczatek;
        while (obecny != nullptr) {
            calosc.DodajElem(obecny->klucz);
            obecny = obecny->nast;
        }

        obecny = z2.poczatek;
        while (obecny != nullptr) {
            calosc.DodajElem(obecny->klucz);
            obecny = obecny->nast;
        }

        return calosc;
    }

};


int main() {
    Zbior l = Zbior();
    l.dodajNaKoncu(2);
    l.dodajNaKoncu(1);
    l.dodajNaKoncu(4);
    l.dodajNaKoncu(3);
    l.dodajNaKoncu(7);

    Zbior pusta = Zbior();
    Zbior pusta2 = Zbior();

    l.DodajElem(7);
    l.DodajElem(5);

    pusta.DodajElem(4);

    Zbior x = l + pusta;
    Zbior y = pusta + pusta2;

    cout << x << endl;
    cout << y;

    return 0;
}