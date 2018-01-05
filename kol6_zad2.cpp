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

    int czyScisleRosnaca() {
        if (glowa == nullptr) {
            return 1;
        }

        EListy *poprzedni = glowa;
        while (poprzedni->nast != nullptr) {
            if (poprzedni->klucz == poprzedni->nast->klucz) {
                return 0;
            }
            poprzedni = poprzedni->nast;
        }

        return 1;
    }

    void uczynScisleRosnaca() {
        if (glowa == nullptr) {
            return;
        }

        EListy *poprzedni = glowa;
        while (poprzedni->nast != nullptr) {
            if (poprzedni->klucz == poprzedni->nast->klucz) {
                EListy *doUsuniecia = poprzedni->nast;
                poprzedni->nast = poprzedni->nast->nast;
                delete doUsuniecia;
            } else {
                poprzedni = poprzedni->nast;
            }
        }
    }
};


int main() {
    ListaUporzadkowana l = ListaUporzadkowana();
    l.wstaw(2);
    l.wstaw(1);
    l.wstaw(4);
    l.wstaw(2);

    ListaUporzadkowana pusta = ListaUporzadkowana();

    int czyS1 = l.czyScisleRosnaca();
    l.uczynScisleRosnaca();
    int czyS2 = l.czyScisleRosnaca();

    int czyS3 = pusta.czyScisleRosnaca();
    pusta.uczynScisleRosnaca();
    int czyS4 = pusta.czyScisleRosnaca();

    l.usunWskazany(2);
    pusta.usunWskazany(3);

    return 0;
}
