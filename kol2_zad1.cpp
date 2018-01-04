#include <iostream>
#include <fstream>

using namespace std;

void processLine(ifstream &i, ostream &o) {
    string imie, nazwisko, plec, stan;
    int wiek = 0;
    i >> imie >> nazwisko >> plec >> wiek >> stan;

    if (wiek >= 67) {
        o << imie << " " << nazwisko << " " << plec << " " << wiek << " " << stan << endl;
    }
}

int main()
{
    ifstream bazaOsob("BazaOsob.txt");
    ofstream emeryci("Emeryci.txt", fstream::out);

    if (!bazaOsob) {
        cout << "b";
    }

    if (!emeryci) {
        cout << "e";
    }

    if (!bazaOsob || !emeryci) {
        throw;
    }

    while (!bazaOsob.eof()) {
        processLine(bazaOsob, emeryci);
    }


    bazaOsob.close();
    emeryci.close();

    return 0;
}