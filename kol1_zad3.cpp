#include <iostream>


int *suma(const int *z1, int z1_len, const int *z2, int z2_len) {
    int *C_temp = new int[z1_len + z2_len];
    int i = 0, j = 0, k = 0;
    while (i < z1_len && j < z2_len) {
        if (z1[i] < z2[j]) {
            C_temp[k] = z1[i];
            ++i;
            ++k;
            continue;
        }
        if (z1[i] > z2[j]) {
            C_temp[k] = z2[j];
            ++j;
            ++k;
            continue;
        }
        // jesli sa rowne:
        C_temp[k] = z1[i];
        ++i;
        ++j;
        ++k;
    }

    while (i < z1_len) {
        C_temp[k] = z1[i];
        ++i;
        ++k;
    }

    while (j < z2_len) {
        C_temp[k] = z2[j];
        ++j;
        ++k;
    }

    int *C = new int[k];

    for (int poz = 0; poz < k; ++poz) {
        C[poz] = C_temp[poz];
    }

    delete [] C_temp;

    return C;
}

int *iloczyn(const int *z1, int z1_len, const int *z2, int z2_len) {
    int *C_temp = new int[z1_len > z2_len ? z1_len : z2_len];
    int i = 0, j = 0, k = 0;
    while (i < z1_len && j < z2_len) {
        if (z1[i] < z2[j]) {
            ++i;
            continue;
        }
        if (z1[i] > z2[j]) {
            ++j;
            continue;
        }
        // jesli sa rowne:
        C_temp[k] = z1[i];
        ++i;
        ++j;
        ++k;
    }

    int *C = new int[k];

    for (int poz = 0; poz < k; ++poz) {
        C[poz] = C_temp[poz];
    }

    delete [] C_temp;

    return C;
}

void wypisz(int *tab, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << tab[i] << ',';
    }
}

int main() {
    int A[]{1, 2, 4, 5, 20}, B[]{4, 5, 11, 30, 31},
            n = 5, m = 5;

    int *C_suma = suma(A, n, B, m);
    wypisz(C_suma, 8);
    std::cout << std::endl;

    int *C_iloczyn = iloczyn(A, n, B, m);
    wypisz(C_iloczyn, 2);
    std::cout << std::endl;

    return 0;
}