/*
 * Problem 11172 Relational Operator
 *
 * Take in 2 numbers and output the relation that is appropriate
 * for the given numbers.
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
        int a, b;
        std::cin >> a >> b;
        if (a == b) {
            output << "=\n";
        } else {
            output << (a < b ? '<' : '>') << '\n';
        }
    }
    std::cout << output.str();
}
