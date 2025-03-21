/*
 * Problem 12015 - Goodle is feeling lucky
 */
#include <iostream>
#include <sstream>

struct list {
    std::string site;
    int rank;
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test {};
    list a[10];
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        output << "Case #" << ++test << ":\n";
        int highestRank {};
        for (int i = 0; i < 10; ++i) {
            std::cin >> a[i].site;
            std::cin >> a[i].rank;
            highestRank = std::max(highestRank, a[i].rank);
        }
        for (int i = 0; i < 10; ++i) {
            if (a[i].rank == highestRank) {
                output << a[i].site << '\n';
            }
        }
    }
    std::cout << output.str();
}
