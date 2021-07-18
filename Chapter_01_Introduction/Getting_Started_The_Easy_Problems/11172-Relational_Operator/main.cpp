/*
 * 11172 Relational Operators
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
        int a {};
        int b {};
        std::cin >> a >> b;
        if (a == b) {
            output << "=\n";
        } else if (a < b) {
            output << "<\n";
        } else {
            output << ">\n";
        }
    }
    std::cout << output.str();
}
