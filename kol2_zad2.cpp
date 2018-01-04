#include <iostream>

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

    int najwiekszy() {
        if (this->glowa == nullptr) {
            throw new logic_error("Lista pusta.");
        }

        EListy *obecny = this->glowa;
        int najwiekszy = obecny->klucz;
        while (obecny->nast != nullptr) {
            obecny = obecny->nast;
            najwiekszy = obecny->klucz > najwiekszy ? obecny->klucz : najwiekszy;
        }

        return najwiekszy;
    }

    void usunWskazany(int klucz) {
        EListy *glowa = this->glowa;
        while (glowa != nullptr && glowa->klucz == klucz) {
            this->glowa = glowa->nast;
            delete glowa;
            glowa = this->glowa;
        }

        if (this->glowa == nullptr) {
            return;
        }

        EListy *poprzedni = this->glowa,
                *obecny = poprzedni->nast;
        while (obecny != nullptr) {
            if (obecny->klucz == klucz) {
                poprzedni->nast = obecny->nast;
                delete obecny;
                obecny = poprzedni->nast;
            } else {
                poprzedni = obecny;
                obecny = obecny->nast;
            }
        }
    }
};


int main() {
    ListaJK l = ListaJK();
    l.dodajNaKoncu(2);
    l.dodajNaKoncu(1);
    l.dodajNaKoncu(4);
    l.dodajNaKoncu(3);
    l.dodajNaKoncu(2);

    ListaJK pusta = ListaJK();

    int n = l.najwiekszy();
    l.usunWskazany(2);
    pusta.usunWskazany(3);

    return 0;
}