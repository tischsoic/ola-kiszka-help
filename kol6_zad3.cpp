#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void maksymalnyNiemalejacy(int *A, int n) {
    vector<vector<int>> wszystkie;
    vector<int> podciagMaks;

    for (int i = 0; i < n; ++i) {
        vector<int> podciag;
        int ostatniaLiczba = A[i];
        podciag.push_back(ostatniaLiczba);
        for (int j = i + 1; j < n; ++j) {
            if (A[j] > ostatniaLiczba) {
                podciag.push_back(A[j]);
                ostatniaLiczba = A[j];
            }
        }

        if (podciag.size() == podciagMaks.size()) {
            wszystkie.push_back(podciag);
        }
        if (podciag.size() > podciagMaks.size()) {
            wszystkie.clear();
            wszystkie.push_back(podciag);
            podciagMaks = podciag;
        }
    }


    for (int i = 0; i < wszystkie.size(); ++i) {
        for (int j = 0; j < wszystkie[i].size(); ++j) {
            cout << wszystkie[i][j] << ", ";
        }
        cout << endl;
    }
}

int main() {
    int A[] = {3, 2, 4, 5, 6, 1, 3, 7};
    int n = 8;

    maksymalnyNiemalejacy(A, n);

    return 0;
}