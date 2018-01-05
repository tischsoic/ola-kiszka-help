#include <iostream>
#include <fstream>

using namespace std;

int iloczyn2LiczbPierwszych(int liczba) {
    int d = 2;
    int iloscDzielen = 0;
    while (iloscDzielen <= 2 && liczba != 1 && d <= liczba) {
        if (liczba % d == 0) {
            liczba = liczba / d;
            ++iloscDzielen;
        } else {
            ++d;
        }
    }

    return iloscDzielen == 2 ? 1 : 0;
}

int main() {
    int il1 = iloczyn2LiczbPierwszych(4);
    int il2 = iloczyn2LiczbPierwszych(8);
    int il3 = iloczyn2LiczbPierwszych(3);
    int il4 = iloczyn2LiczbPierwszych(6);

    return 0;
}