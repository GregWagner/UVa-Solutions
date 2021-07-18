/*
 * 11547 Automatiic Answer
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        int n {};
        std::cin >> n;
        n = std::abs((((n * 63) + 7492) * 5) - 498);
        output << n % 100 / 10 << '\n';
    }

    std::cout << output.str();
}
