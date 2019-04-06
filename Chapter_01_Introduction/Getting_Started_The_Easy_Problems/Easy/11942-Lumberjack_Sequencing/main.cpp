/*
 * Problem 11942 - Lumberjack Sequencing
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    output << "Lumberjacks:\n";
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        bool ascending {true};
        bool descending {true};
        int start;
        std::cin >> start;
        for (int i = 1; i < 10; ++i) {
            int next;
            std::cin >> next;
            if (start >= next) {
                descending = false;
            } else if (start <= next) {
                ascending = false;
            }
            start = next;
        }
        output << (ascending || descending ? "Ordered" : "Unordered") << '\n';
    }
    std::cout << output.str();
}
