#include <iostream>
#include <fstream>

using namespace std;

bool przestawienie(const string a, const string b) {
    if (a.length() != b.length()) {
        return false;
    }

    char aNiezgodne[2], bNiezgodne[2];
    int iloscZmian = 0;
    for (int i = 0; i < a.length(); ++i) {
        if (b[i] != a[i]) {
            ++iloscZmian;
            aNiezgodne[iloscZmian] = a[i];
            bNiezgodne[iloscZmian] = b[i];
        }
    }

    if (iloscZmian != 2) {
        return false;
    }

    return aNiezgodne[1] == bNiezgodne[2] && aNiezgodne[2] == bNiezgodne[1];
}



int main() {
    bool s1 = przestawienie("abba", "baba");
    bool s2 = przestawienie("karol", "koral");
    bool s3 = przestawienie("karol", "kolar");

    ifstream slownik("slownik.txt");

    ofstream przestawianki("Przestawianki.txt", fstream::out);

    for(int i = 0; !slownik.eof(); ++i) {
        string slowo;
        slownik >> slowo;

        ifstream slownik2("slownik2.txt");


        for (int j = 0; j <= i; ++j) {
            slownik2.ignore(31, '\n');
        }

        while(!slownik2.eof()) {
            string slowo2;
            slownik2 >> slowo2;

            if (przestawienie(slowo, slowo2)) {
                przestawianki << slowo << " " << slowo2 << endl;
            }
        }

        slownik2.close();
    }

    slownik.close();
    przestawianki.close();

    return 0;
}