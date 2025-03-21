/*
 * 11942 Lumberjack Sequencing
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    output << "Lumberjacks:\n";
    int testCases {};
    std::cin >> testCases;
    while (testCases--) {
        bool goingUp {true};
        bool goingDown {true};
        int previousHeight {};
        std::cin >> previousHeight;
        for (int i {1}; i < 10; ++i) {
            int height {};
            std::cin >> height;
            if (previousHeight >= height) {
                goingUp = false;
            } else if (previousHeight <= height) {
                goingDown = false;
            }
            previousHeight = height;
        }
        output << (goingUp || goingDown ? "Ordered\n" : "Unordered\n");
    }
    std::cout << output.str();
}
