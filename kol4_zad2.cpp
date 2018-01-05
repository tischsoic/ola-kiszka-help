#include <iostream>
#include <fstream>

using namespace std;
struct EListy {
    int klucz;
    EListy *nast = nullptr;
};

class ListaJK {
    EListy *glowa = nullptr;

public:
    void dodajNaKoncu(int klucz) {
        EListy *nowyEl = new EListy();
        nowyEl->klucz = klucz;

        if (this->glowa == nullptr) {
            this->glowa = nowyEl;
            return;
        }

        EListy *ostatni = this->glowa;
        while (ostatni->nast != nullptr) {
            ostatni = ostatni->nast;
        }

        ostatni->nast = nowyEl;
    }

    void dodajNaKoncuJesliNieBylo(int klucz) {
        EListy *nowyEl = new EListy();
        nowyEl->klucz = klucz;

        if (this->glowa == nullptr) {
            this->glowa = nowyEl;
            return;
        }

        EListy *obecny = this->glowa,
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

};


int main() {
    ListaJK l = ListaJK();
    l.dodajNaKoncu(2);
    l.dodajNaKoncu(1);
    l.dodajNaKoncu(4);
    l.dodajNaKoncu(3);
    l.dodajNaKoncu(7);

    ListaJK pusta = ListaJK();

    l.dodajNaKoncuJesliNieBylo(7);
    l.dodajNaKoncuJesliNieBylo(5);

    pusta.dodajNaKoncuJesliNieBylo(4);

    return 0;
}