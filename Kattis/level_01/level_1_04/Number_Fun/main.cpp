/*
 * Number Fun
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        bool possible {};
        if (a + b == c) {
            possible = true;
        } else if (a - b == c || b - a == c) {
            possible = true;
        } else if (a * b == c) {
            possible = true;
        } else if (c * b == a || a * c == b) {
            possible = true;
        }
        output << (possible ? "Possible" : "Impossible") << '\n';
    }
    std::cout << output.str();
}
