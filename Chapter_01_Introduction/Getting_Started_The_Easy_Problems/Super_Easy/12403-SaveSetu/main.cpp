/*
 * Problem 12403 Save Setu
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int balance {};
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        std::string cmd;
        std::cin >> cmd;
        if (cmd == "donate") {
            int amount;
            std::cin >> amount;
            balance += amount;
        } else {
            output << balance << '\n';
        }
    }
    std::cout << output.str();
}
