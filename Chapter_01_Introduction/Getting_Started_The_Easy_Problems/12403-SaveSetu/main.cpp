/*
 * 12403 Save Setu
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int numberOfOperations {};
    std::cin >> numberOfOperations;
    int money {};
    while (numberOfOperations--) {
        std::string s;
        std::cin >> s;
        if (s == "donate") {
            int amount {};
            std::cin >> amount;
            money += amount;
        } else {
            output << money << '\n';
        }
    }
    std::cout << output.str();
}
