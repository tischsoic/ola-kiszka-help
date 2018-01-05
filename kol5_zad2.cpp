#include <iostream>
#include <fstream>

using namespace std;

struct EListy {
    int klucz;
    EListy *nast = nullptr;
};

class ListaUporzadkowana {
    EListy *glowa = nullptr;

public:
    void wstaw(int klucz) {
        EListy *nowyEl = new EListy();
        nowyEl->klucz = klucz;

        if (this->glowa == nullptr || this->glowa->klucz >= klucz) {
            nowyEl->nast = this->glowa;
            this->glowa = nowyEl;
            return;
        }

        EListy *obecny = this->glowa;
        while (obecny->nast != nullptr && obecny->nast->klucz < klucz) {
            obecny = obecny->nast;
        }

        nowyEl->nast = obecny->nast;
        obecny->nast = nowyEl;
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
    ListaUporzadkowana l = ListaUporzadkowana();
    l.wstaw(2);
    l.wstaw(1);
    l.wstaw(4);
    l.wstaw(3);

    ListaUporzadkowana pusta = ListaUporzadkowana();

    l.usunWskazany(2);
    pusta.usunWskazany(3);

    return 0;
}