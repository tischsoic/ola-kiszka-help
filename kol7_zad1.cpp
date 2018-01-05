#include <iostream>
#include <fstream>

using namespace std;

class Zbior {
    int n;
    float tab[100];

public:
    Zbior(): n(0) {}

    float czyNalezy(float x) const {
        for (int i = 0; i < n; ++i) {
            if (tab[i] == x) {
                return 1;
            }
        }

        return 0;
    }

    void dodajElem(float x) {
        if (!this->czyNalezy(x)) {
            tab[n] = x;
            ++n;
        }
    }

    void usunElement(float x) {
        for (int i = 0; i < n; ++i) {
            if (tab[i] == x) {
                for (int j = i+1; j < n; ++j) {
                    tab[j - 1] = tab[j];
                    --n;
                }

                return;
            }
        }
    }

    friend Zbior operator+(Zbior z1, const Zbior &z2) {
        for (int i = 0; i < z2.n; ++i) {
            z1.dodajElem(z2.tab[i]);
        }

        return z1;
    }

    friend Zbior operator-(Zbior z1, const Zbior &z2) {
        for (int i = 0; i < z2.n; ++i) {
            z1.usunElement(z2.tab[i]);
        }

        return z1;
    }

    friend Zbior operator*(const Zbior &z1, const Zbior &z2) {
        Zbior z3;
        for (int i = 0; i < z1.n; ++i) {
            float elem = z1.tab[i];
            if (z2.czyNalezy(elem)) {
                z3.dodajElem(elem);
            }
        }

        return z3;
    }

    friend istream &operator>>(istream &input, Zbior &z) {
        cout << "Podaj ilosc: ";

        cin >> z.n;

        cout << "Podaj liczby: ";
        for (int i = 0; i < z.n; ++i) {
            input >> z.tab[i];
        }

        return input;
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
        z4 = z1 * z2,
        z5 = z1 - z2;

    z3.usunElement(3);

    Zbior wczytany;
    cin >> wczytany;

    return 0;
}