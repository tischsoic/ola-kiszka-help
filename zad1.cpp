#include <iostream>

using namespace std;

class Macierz {
    int m;
    float tab[10][10];

    int readNumber(istream *is) {
        int a;
        (*is) >> a;
        return a;
    }

    bool checkNextChar(char c, istream *is) {
        int next_char = is->peek();
        return next_char == c;
    }

    bool isNextRow(istream *is) {
        return this->checkNextChar(';', is);
    }

    bool isEnd(istream *is) {
        return this->checkNextChar('\n', is);
    }

    int readRow(istream *is, int row_num) {
        for (int i = 0; true; ++i) {
            this->tab[row_num][i] = this->readNumber(is);
            if (this->isNextRow(is) || this->isEnd(is)) {
                return ++i;
            }
            is->ignore();
        }
    }

public:
    Macierz(): m(0) {}

    friend istream &operator>>(istream &input, Macierz &macierz) {
        int m = 0;
        int row = 0;

        while (true) {
            m = macierz.readRow(&input, row);
            ++row;
            if (macierz.isEnd(&input)) {
                break;
            }
            input.ignore();
        }

        macierz.m = m;

        return input;
    }

    friend ostream &operator<<(ostream &output, const Macierz &macierz) {
        output << '(';

        for (int i = 0; i < macierz.m; ++i) {
            for (int j = 0; j < macierz.m; ++j) {
                output << macierz.tab[i][j];

                if (j != macierz.m - 1) {
                    output << ',';
                }
            }

            if (i != macierz.m - 1) {
                output << ';';
            }
        }

        output << ')';

        return output;
    }

    friend Macierz operator+(Macierz m1, const Macierz &m2) {
        if (m1.m != m2.m) {
            throw;
        }

        for (int i = 0; i < m1.m; ++i) {
            for (int j = 0; j < m1.m; ++j) {
                m1.tab[i][j] += m2.tab[i][j];
            }
        }

        return m1;
    }

    friend Macierz operator*(Macierz m1, const Macierz &m2) {
        if (m1.m != m2.m) {
            throw;
        }
        Macierz m3;
        m3.m = m1.m;
        for (int i = 0; i < m1.m; ++i) {
            for (int j = 0; j < m2.m; ++j) {
                int a = 0;
                for (int k = 0; k < m1.m; ++k) {
                    a += m1.tab[i][k] * m2.tab[k][j];
                }

                m3.tab[i][j] = a;
            }
        }

        return m3;
    }

    friend Macierz operator^(Macierz m1, const int &s) {
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

    cout << m2 * m1 << endl;
    cout << m2 + m1 << endl;

    cin >> m1;
    cout << m1 << endl;
    cout << (m1 ^ 2) << endl;

    return 0;
}