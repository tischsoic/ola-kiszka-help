#include <iostream>
#include <fstream>

using namespace std;

class Zbior {
    int n;
    int tab[100];

public:
    Zbior(): n(0) {}

    int czyNalezy(int x) const {
        for (int i = 0; i < n; ++i) {
            if (tab[i] == x) {
                return 1;
            }
        }

        return 0;
    }

    void dodajElem(int x) {
        if (!this->czyNalezy(x)) {
            tab[n] = x;
            ++n;
        }
    }

    friend Zbior operator+(Zbior z1, const Zbior &z2) {
        for (int i = 0; i < z2.n; ++i) {
            z1.dodajElem(z2.tab[i]);
        }

        return z1;
    }

    friend Zbior operator*(const Zbior &z1, const Zbior &z2) {
        Zbior z3;
        for (int i = 0; i < z1.n; ++i) {
            int elem = z1.tab[i];
            if (z2.czyNalezy(elem)) {
                z3.dodajElem(elem);
            }
        }

        return z3;
    }
};

int main() {
    Zbior z1;
    z1.dodajElem(1);
    z1.dodajElem(2);
    z1.dodajElem(3);

    Zbior z2;
    z2.dodajElem(2);
    z2.dodajElem(3);
    z2.dodajElem(4);

    Zbior z3 = z1 + z2,
        z4 = z1 * z2;

    return 0;
}