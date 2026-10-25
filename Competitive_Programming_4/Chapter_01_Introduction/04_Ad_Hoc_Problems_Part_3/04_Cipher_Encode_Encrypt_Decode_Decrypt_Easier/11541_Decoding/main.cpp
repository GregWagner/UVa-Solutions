// 11541 Decoding
#include <cctype>
#include <iostream>
#include <limits>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testNumber{1};
    int testCases;
    std::cin >> testCases;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (testCases--) {
        std::string input;
        std::getline(std::cin, input);

        std::string outputString;
        char letter{};
        int count{};
        for (const auto& c : input) {
            if (std::isdigit(static_cast<unsigned char>(c))) {
                count = count * 10 + (c - '0');
            } else {
                if (letter != 0) {
                    outputString.append(count, letter);
                }
                letter = c;
                count = 0;
            }
        }
        if (letter != 0) {
            outputString.append(count, letter);
        }
        output << "Case " << testNumber++ << ": " << outputString << '\n';
    }
    std::cout << output.str();
}
