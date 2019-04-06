/*
 * Problem 12577 - Hajj-e-Akbar
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int test {1};

    std::string input;
    while (std::cin >> input && input != "*") {
        output << "Case " << test++ << ": Hajj-e-"
            << (input == "Hajj" ? "Akbar" : "Asghar") << '\n';
    }
    std::cout << output.str();
}
