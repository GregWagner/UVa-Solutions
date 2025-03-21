/*
 * Problem 11494 - Queen
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int fromX, fromY, toX, toY;
    while (std::cin >> fromX >> fromY >> toX >> toY) {
        if (fromX == 0)
            break;
        if (fromX == toX && fromY == toY) {
            output << "0\n";
        } else if (fromX == toX || fromY == toY) {
            output << "1\n";
        } else if (std::abs(fromX - toX) == std::abs(fromY - toY)) {
            output << "1\n";
        } else {
            output << "2\n";
        }
    }
    std::cout << output.str();
}
