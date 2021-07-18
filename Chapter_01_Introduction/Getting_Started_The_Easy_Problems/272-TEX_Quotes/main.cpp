/*
 * 272 TEX quotes
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
   
    std::ostringstream output;

    std::string input;
    bool start {true};
    while (std::getline(std::cin, input)) {
        for (const auto &c : input) {
            if (c == '\"') {
                output << (start ? "``" : "''");
                start = !start;
            } else {
                output << c;
            }
        }
        output << '\n';
    }
    std::cout << output.str();
}
