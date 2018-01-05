#include <iostream>

using namespace std;

class Macierz {
    int m, n;
    int tab[9][9];

    int readNumber(istream *is) {
        int a;
        (*is) >> a;
        return a;
    }

    bool checkNextChar(char c, istream *is) {
        int next_char = is->peek();
        // is->ignore();

        // cout << endl
        //      << next_char;
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
    Macierz() {
        m = 2;
        n = 2;
    }

    friend istream &operator>>(istream &input, Macierz &macierz) {
        int m = 0;
        int n = 0;

        while (true) {
//            cout << 'w';
            n = macierz.readRow(&input, m);
            ++m;
            if (macierz.isEnd(&input)) {
                break;
            }
            input.ignore();
        }
//        cout << "2";

        macierz.m = m;
        macierz.n = n;

        return input;
    }

    friend ostream &operator<<(ostream &output, const Macierz &macierz) {
        output << '(';

        for (int i = 0; i < macierz.m; ++i) {
            for (int j = 0; j < macierz.n; ++j) {
                output << macierz.tab[i][j];

                if (j != macierz.n - 1) {
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

    friend Macierz operator*(Macierz m, const int &s) {
        for (int i = 0; i < m.m; ++i) {
            for (int j = 0; j < m.n; ++j) {
                m.tab[i][j] *= s;
            }
        }

        return m;
    }

    friend Macierz operator*(Macierz m1, const Macierz &m2) {
        if (m1.m != m2.n || m1.n != m2.m) {
            throw;
        }
        Macierz m3;
        m3.m = m1.m;
        m3.n = m2.n;
        for (int i = 0; i < m1.m; ++i) {
            for (int j = 0; j < m2.n; ++j) {
                int a = 0;
                for (int k = 0; k < m1.n; ++k) {
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
//    std::cout << "aaa" << endl;

//    Macierz a;
//    cin >> a;
//    cout << a << endl;

    Macierz m1, m2;
    cin >> m1;
    cout << m1 << endl;
    cin >> m2;
    cout << m2 << endl;

    cout << m1 * 2 << endl;
    cout << m2 * m1 << endl;

    cin >> m1;
    cout << m1 << endl;
    cout << (m1 ^ 2) << endl;

    return 0;
}