#include <iostream>
#include <fstream>

using namespace std;


int jestPodciagiem(int *A, int *B, int m, int n) {
    for (int i = 0, APosition = 0; i < n; ++i) {
        if (APosition == m - 1) {
            return 1;
        }
        if (B[i] == A[APosition]) {
            ++APosition;
        }
    }

    return 0;
}

int main() {
    int B[] = {3,2,4,5,6,1,3,7},
        A[] = {2,5,3};

    int czyJest = jestPodciagiem(A, B, 3, 8);

    return 0;
}