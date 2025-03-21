#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;

    std::string input;
    while (std::getline(std::cin, input)) {
        bool left {true};
        for (const auto &c : input) {
            if (c == '"') {
                output << (left ? "``" : "''");
                left = !left;
            } else {
                output << c;
            }
        }
        output << '\n';
    }
    std::cout << output.str();
}
