#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    std::string input;
    while (std::getline(std::cin, input)) {
        output << input << '\n';
    }

    std::cout << output.str();
}