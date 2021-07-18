/*
 * 11044 Searching for Nessy
 *
 * One liner code/formula exists
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
        int m {};
        std::cin >> n >> m;
        output << (n / 3) * (m / 3) << '\n';
    }
    std::cout << output.str();
}
