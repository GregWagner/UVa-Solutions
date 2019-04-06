/*
 * Problem 12468 - Zapping
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int a, b;
    while (std::cin >> a >> b && a != -1 && b != -1) {
        int up {};
        int down {};
        if (a < b) {
            up = b - a;
            down = a + 100 - b;
        } else if (a > b) {
            up = 100 - a + b;
            down = a - b;
        } else {
            up = down = 0;
        }
        output << std::min(up, down) << '\n';
    }
    std::cout << output.str();
}
