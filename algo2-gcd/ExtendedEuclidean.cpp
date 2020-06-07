#include <iostream>

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main(int argc, char *argv[]) {
    int x, y;
    int res = gcd(20, 14, x, y);
    std::cout << x << "*20 + " << y << "*14 = " << res << std::endl;
}