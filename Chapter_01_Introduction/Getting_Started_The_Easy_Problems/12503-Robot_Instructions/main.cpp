/*
 * 12503 Robot Instructions
 */
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases--) {
        int position {};
        int numberOfInstructions {};
        std::cin >> numberOfInstructions;
        std::vector<std::string> instructions(numberOfInstructions + 1);
        for (int i {1}; i < numberOfInstructions + 1; ++i) {
            std::string operation;
            std::cin >> operation;
            if (operation == "SAME") {
                int step {};
                std::cin >> operation >> step;
                operation = instructions[step];
            }
            operation == "LEFT" ? --position : ++position;
            instructions[i] = operation;
        }
        output << position << '\n';
    }
    std::cout << output.str();
}
