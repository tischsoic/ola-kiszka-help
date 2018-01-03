#include <iostream>

using namespace std;

class Macierz
{
    int m, n;
    int tab[9][9];

    int readNumber(istream *is)
    {
        int a;
        (*is) >> a;
        return a;
    }

    bool checkNextChar(char c, istream *is)
    {
        int next_char = is->peek();
        // is->ignore();

        // cout << endl
        //      << next_char;
        return next_char == c;
    }

    bool isNextRow(istream *is)
    {
        return this->checkNextChar(';', is);
    }

    bool isEnd(istream *is)
    {
        return this->checkNextChar('\n', is);
    }

    int readRow(istream *is, int row_num)
    {
        for (int i = 0; true; ++i)
        {
            this->tab[row_num][i] = this->readNumber(is);
            if (this->isNextRow(is) || this->isEnd(is))
            {
                return ++i;
            }
            is->ignore();
        }
    }

  public:
    Macierz()
    {
        m = 2;
        n = 2;
    }

    friend istream &operator>>(istream &input, Macierz &macierz)
    {
        int m = 0;
        int n = 0;

        while (true)
        {
            cout << 'w';
            n = macierz.readRow(&input, m);
            ++m;
            if (macierz.isEnd(&input))
            {
                break;
            }
            input.ignore();
        }
        cout << "2";

        macierz.m = m;
        macierz.n = n;

        return input;
    }

    friend ostream &operator<<(ostream &output, const Macierz &macierz)
    {
        output << '(';

        for (int i = 0; i < macierz.m; ++i)
        {
            for (int j = 0; j < macierz.n; ++j)
            {
                output << macierz.tab[i][j];

                if (j != macierz.n - 1)
                {
                    output << ',';
                }
            }

            if (i != macierz.m - 1)
            {
                output << ';';
            }
        }

        output << ')';

        return output;
    }
};

int main()
{
    std::cout << "aaa";

    Macierz a;
    cin >> a;
    cout << a;

    return 0;
}