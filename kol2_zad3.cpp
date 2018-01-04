#include <iostream>
#include <cmath>

using namespace std;

class Trojmian {
    float a, b, c;

public:
    Trojmian() : a(0), b(0), c(0) {}

    Trojmian(float _a, float _b, float _c) : a(_a), b(_b), c(_c) {}

    float pierwiastki() {
        float delta = b * b - 4 * a *c;
        float x1 = (-b + sqrt (delta)) / (2 * a);
        float x2 = (-b - sqrt (delta)) / (2 * a);

        cout << "x1: " << x1 << ", x2: " << x2 << endl;

        return x1 > x2 ? x1 : x2;
    }

    friend istream &operator>>(istream &input, Trojmian &t)
    {
        input >> t.a >> t.b >> t.c;

        return input;
    }

    friend ostream &operator<<(ostream &output, const Trojmian &t)
    {
        output << t.a << "x^2 + " << t.b << "x + " << t.c;

        return output;
    }

    friend Trojmian operator+(Trojmian t1, const Trojmian &t2) {
        t1.a = t1.a + t2.a;
        t1.b = t1.b + t2.b;
        t1.c = t1.c + t2.c;

        return t1;
    }

    friend Trojmian operator*(Trojmian t1, const float &w) {
        t1.a = t1.a * w;
        t1.b = t1.b * w;
        t1.c = t1.c * w;

        return t1;
    }
};

int main() {
    Trojmian t1 {0.3, 0.4, 0.5},
    t2 {0.4, 0.6, 0.6};

    cout << t1 << endl << t2 << endl << (t1 * 2) << endl << (t1 + t2) << endl;

    Trojmian t3;
    cin >> t3;
    cout << endl << t3 << endl;

    return 0;
}