#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cenyAkcji("CenyAkcjiX.txt");

    if (!cenyAkcji) {
        throw;
    }

    float budzet = 1000;
    int iloscAkcji = 0;
    float cenaAkcji = 0;

    float a,b;
    cenyAkcji >> a;
    while (!cenyAkcji.eof()) {
        cenyAkcji >> b;

        float roznica1 = b - a;
        if (roznica1 > 0 && iloscAkcji == 0) {
            // kupuj
            iloscAkcji = budzet / a;
            budzet -= iloscAkcji * a;
            cenaAkcji = a;
        } else if (roznica1 < 0 && iloscAkcji > 0) {
            // sprzedawaj
            budzet += iloscAkcji * a;
            iloscAkcji = 0;
        }

        a = b;
    }

    budzet += iloscAkcji * cenaAkcji;

    float zysk = budzet - 1000;
    cout << zysk;

    cenyAkcji.close();

    return 0;
}