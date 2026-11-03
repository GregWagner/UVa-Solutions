#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto getAcronym(const std::string& line) -> std::string {
    std::stringstream ss(line);
    std::string word;
    std::string acronym = "";
    while (ss >> word) {
        if (!word.empty()) {
            acronym += tolower(word[0]);
        }
    }
    return acronym;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string line1, line2;
    while (std::getline(std::cin, line1)) {
        if (!std::getline(std::cin, line2)) {
            break;
        }

        std::string acr1{getAcronym(line1)};
        std::string acr2{getAcronym(line2)};

        if (acr1 == acr2) {
            output << "yes\n";
        } else {
            output << "no\n";
        }
    }
    std::cout << output.str();
}