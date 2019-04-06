/*
 * Quick Estimate
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
        std::string n;
        std::cin >> n;
        output << n.length() << '\n';
    }
    std::cout << output.str();
}
