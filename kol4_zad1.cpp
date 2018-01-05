#include <iostream>
#include <fstream>

using namespace std;

class Macierz {
    float a, b, c, d;

public:
    Macierz() : a(0), b(0), c(0), d(0) {}

    Macierz(float _a, float _b, float _c, float _d) : a(_a), b(_b), c(_c), d(_d) {}

    float det() {
        return a * c - b * d;
    }

    friend istream &operator>>(istream &input, Macierz &macierz) {
        input >> macierz.a >> macierz.b;
        input.ignore();
        input >> macierz.c >> macierz.d;

        return input;
    }

    friend ostream &operator<<(ostream &output, const Macierz &macierz) {
        output << '(';
        output << macierz.a << ',' << macierz.b << ';' << macierz.c << ',' << macierz.d;
        output << ')';

        return output;
    }

    friend Macierz operator*(Macierz m, const int &s) {
        m.a *= s;
        m.b *= s;
        m.c *= s;
        m.d *= s;

        return m;
    }

    friend Macierz operator*(Macierz m1, const Macierz &m2) {
        Macierz m3;

        m3.a = m1.a * m2.a + m1.b * m2.c;
        m3.b = m1.a * m2.b + m1.b * m2.d;
        m3.c = m1.c * m2.a + m1.d * m2.c;
        m3.d = m1.c * m2.b + m1.d * m2.d;

        return m3;
    }

    friend Macierz operator^(Macierz m1, const int &s) {
        if (s == 0) {
            m1.a = 1;
            m1.d = 1;

            m1.b = 0;
            m1.c = 0;

            return m1;
        }

        for (int i = 1; i < s; ++i) {
            m1 = m1 * m1;
        }

        return m1;
    }
};


int main() {
    Macierz m1, m2;
    cin >> m1;
    cout << m1 << endl;
    cin >> m2;
    cout << m2 << endl;

    cout << m1 * 2 << endl;
    cout << m2 * m1 << endl;

    cin >> m1;
    cout << m1 << endl;
    cout << (m1 ^ 0) << endl;
    cout << (m1 ^ 2) << endl;

    return 0;
}