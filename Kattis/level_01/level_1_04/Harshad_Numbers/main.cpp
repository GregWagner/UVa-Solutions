/*
 * Harshad Numbers
 */
#include <iostream>

int sum(int n) {
    int results {};
    while (n > 0) {
        results += n % 10;
        n /= 10;
    }
    return results;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    while (true) {
        if (n % sum(n) == 0) {
            std::cout << n << '\n';
            break;
        }
        ++n;
    }
}
