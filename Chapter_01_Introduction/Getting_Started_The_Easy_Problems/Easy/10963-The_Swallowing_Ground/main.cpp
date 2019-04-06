/*
 * Problem 10963 - The Swallowing Ground
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    bool first {true};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int numberOfColumns;
        std::cin >> numberOfColumns;
        int x, y;
        std::cin >> x >> y;
        int gap = x - y;
        bool closeable {true};
        for (int i = 1; i < numberOfColumns; ++i) {
            std::cin >> x >> y;
            if (gap != (x - y)) {
                closeable = false;
            }
        }
        output << (first ? "" : "\n");
        first = false;
        output << (closeable ? "yes" : "no") << '\n';
    }
    std::cout << output.str();
}
