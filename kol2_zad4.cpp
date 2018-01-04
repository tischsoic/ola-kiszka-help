#include <iostream>

using namespace std;

float odleglosc(int liczba, int odpowiedz) {
    return abs(liczba - odpowiedz);
}

int main() {
    int punkty1{0},
            punkty2{0};

    while (punkty1 != 3 && punkty2 != 3) {
        int liczba = rand() % 31 - 15;
        int odpowiedz1, odpowiedz2;

        cout << "Podaj liczbe: ";
        cin >> odpowiedz1;
        cout << endl;
        cout << "Podaj liczbe: ";
        cin >> odpowiedz2;
        cout << endl;

        int odleglosc1 = odleglosc(liczba, odpowiedz1),
                odleglosc2 = odleglosc(liczba, odpowiedz2);

        cout << "Liczba to:" << liczba << endl;
        if (odleglosc1 == odleglosc2) {
            cout << "obaj gracze" << endl;
        } else if (odleglosc1 < odleglosc2) {
            cout << "gracz 1." << endl;
            ++punkty1;
        } else {
            cout << "gracz 2." << endl;
            ++punkty2;
        }
    }

    cout << "wygrał ";
    if (punkty1 == punkty2) {
        cout << "obaj gracze" << endl;
    } else if (punkty1 < punkty2) {
        cout << "gracz 1." << endl;
        ++punkty1;
    } else {
        cout << "gracz 2." << endl;
        ++punkty2;
    }

    return 0;
}