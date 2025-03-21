/*
 * Problem 12503 - Robot Instructions
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    std::string a[110] {};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int position {};
        int index {1};
        int instructions;
        std::cin >> instructions;
        while (instructions--) {
            std::string op;
            std::cin >> op;
            if (op == "SAME") {
                int copy;
                std::cin >> op >> copy;     // read in AS
                op = a[copy];
            }
            a[index++] = op;
            op == "RIGHT" ? ++position : --position;
        }
        output << position << '\n';
    }
    std::cout << output.str();
}
