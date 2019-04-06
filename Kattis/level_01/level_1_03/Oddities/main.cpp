/*
 * Oddities
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;

    int n;
    std::cin >> n;
    for (int i {}; i < n; ++i) {
        int x;
        std::cin >> x;
        output << x << " is " << (x % 2 == 0 ? "even\n" : "odd\n");
    }
    std::cout << output.str();
}
