/*
 * Problem 10849 - Move the Bishop
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
        int numberOfTests;
        std::cin >> numberOfTests;
        long n;
        std::cin >> n;

        for (int i {}; i < numberOfTests; ++i) {
            long fromX, fromY, toX, toY;
            std::cin >> fromX >> fromY >> toX >> toY;

            if (fromX == toX && fromY == toY) {
                output << "0\n";
            } else if (std::abs(fromX - toX) == std::abs(fromY - toY)) {
                output << "1\n";
            } else if ((fromX + fromY) % 2 == (toX + toY) % 2) {
                output << "2\n";
            } else {
                output << "no move\n";
            }
        }
    }
    std::cout << output.str();
}
