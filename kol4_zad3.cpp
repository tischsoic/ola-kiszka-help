#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int wartoscLitery(char l) {
    switch (l) {
        case 'ą':
            return 5;
        case 'b':
            return 3;
        case 'c':
            return 2;
        case 'ź':
            return 9;
        case 'ż':
            return 5;
        default:
            return 1;
    }
}

int wartoscSlowa(string slowo) {
    int wartosc = 0;
    for (int i = 0; i < slowo.length(); ++i) {
        wartosc += wartoscLitery(slowo[i]);
    }

    return wartosc;
}

bool daSieUlozycSlowo(string slowo, string zestawLiter) {
    bool zuzyta[7] = {false};

    for (int i = 0; i < slowo.length(); ++i) {
        char litera = slowo[i];

        int pozycjaWZestawie = -1;
        for (int j = 0; j < zestawLiter.length(); ++j) {
            char literaZZestawu = zestawLiter[j];
            if (literaZZestawu == litera && !zuzyta[j]) {
                pozycjaWZestawie = j;
                zuzyta[j] = true;
                break;
            }
        }
        if (pozycjaWZestawie == -1) {
            return false;
        }
    }

    return true;
}

int main() {
    string zestawLiter = "abcda";
    string slowo = "abcada";

    int w = wartoscSlowa(slowo);
    bool d = daSieUlozycSlowo(slowo, zestawLiter);

    ifstream slownik("SlownikScrabble.txt");
    ofstream najwartosciowsze("najwartosciowszeSlowa.txt", fstream::out);

    if (!slownik) {
        cout << "b";
    }

    if (!najwartosciowsze) {
        cout << "e";
    }

    vector<string> najw;
    int najwWartosc = 0;

    while (!slownik.eof()) {
        slownik >> slowo;
        if (daSieUlozycSlowo(slowo, zestawLiter)) {
            int wart = wartoscSlowa(slowo);

            if (wart > najwWartosc) {
                najwWartosc = wart;
                najw.clear();
                najw.push_back(slowo);
            } else if (wart == najwWartosc) {
                najw.push_back(slowo);
            }
        }
    }

    for (int i = 0; i < najw.size(); ++i) {
        najwartosciowsze << najw[i] << '\n';
    }

    najwartosciowsze.close();
    slownik.close();

    return 0;
}