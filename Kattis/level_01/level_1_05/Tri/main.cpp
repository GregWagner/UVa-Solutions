/*
 * Tri
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int a, b, c;
    std::cin >> a >> b >> c;
    if (a + b == c) {
        std::cout << a << "+" << b << "=" << c << '\n';
    } else if (a == b + c) {
        std::cout << a << "=" << b << "+" << c << '\n';
    } else if (a - b == c) {
        std::cout << a << "-" << b << "=" << c << '\n';
    } else if (a == b - c) {
        std::cout << a << "=" << b << "-" << c << '\n';
    } else if (a * b == c) {
        std::cout << a << "*" << b << "=" << c << '\n';
    } else if (a == b * c) {
        std::cout << a << "=" << b << "*" << c << '\n';
    } else if (b != 0 && a / b == c) {
        std::cout << a << "+" << b << "=" << c << '\n';
    } else if (a == b / c) {
        std::cout << a << "=" << b << "/" << c << '\n';
    }
}
