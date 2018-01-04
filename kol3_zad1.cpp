#include <iostream>
#include <cmath>

using namespace std;

class Wektor {
    float x, y, z;
public:
    Wektor() : x(0), y(0), z(0) {}

    Wektor(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    float dlugosc() {
        return sqrt(x * x + y * y + z * z);
    }

    friend istream &operator>>(istream &input, Wektor &w) {
        input >> w.x >> w.y >> w.z;

        return input;
    }

    friend ostream &operator<<(ostream &output, const Wektor &w) {
        output << "[" << w.x << "," << w.y << "," << w.z << "]";

        return output;
    }

    friend Wektor operator+(Wektor w1, const Wektor &w2) {
        w1.x = w1.x + w2.x;
        w1.y = w1.y + w2.y;
        w1.z = w1.z + w2.z;

        return w1;
    }

    friend Wektor operator*(Wektor w1, const float &a) {
        w1.x *= a;
        w1.y *= a;
        w1.z *= a;

        return w1;
    };

    friend float operator*(Wektor w1, const Wektor &w2) {
        return w1.x * w2.x + w1.y * w2.y + w1.z * w2.z;
    };
};


int main() {
    Wektor w1 {1,2,3},
        w2 {1,1,1};

    cout << w1 << endl << (w1 * w2) << endl << (w1 * 2) << endl << (w1 + w2) << endl;

    Wektor w3 {};

    cin >> w3;
    cout << w3;


    return 0;
}