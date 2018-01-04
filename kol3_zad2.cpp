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

    float sredniaArytmetyczna() {
        if (glowa == nullptr) {
            return 0;
        }

        EListy *obecny = glowa;
        int suma = 0;
        int i = 0;

        for (; obecny != nullptr; ++i, obecny = obecny->nast) {
            suma += obecny->klucz;
        }

        return (float)suma / i;
    }

    void usunNajwiekszy() {
        if (glowa == nullptr) {
            return;
        }

        EListy *najwieszky = glowa,
            *poprzedzajacy = nullptr;

        EListy *obecny = glowa->nast,
            *obecnyPoprzedzajacy = glowa;
        while (obecny != nullptr) {
            if (obecny->klucz > najwieszky->klucz) {
                najwieszky = obecny;
                poprzedzajacy = obecnyPoprzedzajacy;
            }

            obecny = obecny->nast;
            obecnyPoprzedzajacy = obecnyPoprzedzajacy->nast;
        }

        if (poprzedzajacy == nullptr) {
            glowa = najwieszky->nast;
        } else {
            poprzedzajacy->nast = najwieszky->nast;
            delete najwieszky;
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

    float sr = l.sredniaArytmetyczna();
    float srP = pusta.sredniaArytmetyczna();

    l.usunNajwiekszy();
    pusta.usunNajwiekszy();


    return 0;
}