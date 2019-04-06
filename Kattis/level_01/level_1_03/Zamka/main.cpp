/*
 * Zamka
 */
#include <iostream>

int sumOfDigits(int x) {
    int sum {};
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int l, d, x;
    std::cin >> l >> d >> x;
    for (int i {l}; i <= d; ++i) {
        if (sumOfDigits(i) == x) {
            std::cout << i << '\n';
            break;
        }
    }
    for (int i {d}; i >= l; --i) {
        if (sumOfDigits(i) == x) {
            std::cout << i << '\n';
            break;
        }
    }
}
