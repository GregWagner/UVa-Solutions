/*
 * Problem 695 - How Many Knights
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::ostringstream output;

    int x, y;
    while ((std::cin >> x >> y) && (x != 0 || y != 0)) {
        int knights {0};
        int min = std::min(x, y);
        int max = std::max(x, y);
        if (min == 0) {
            knights = 0;
        } else if (min == 1) {
            knights = max;
        } else if (min == 2) {
            // kk..
            // kk..
            knights = 2 * (((max + 3) / 4) + ((max + 2) / 4));
        } else {
            // k.k.k
            // .k.k.
            // k.k.k
            // .k.k.k
            knights = ((min + 1) / 2) * ((max + 1) / 2) +
                (min / 2) * (max / 2);
        }
        output << knights << " knights may be placed on a "
            << x << " row " << y << " column board.\n";
    }
    std::cout << output.str();
}
