// 490 Rotating Sentences
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    std::vector<std::string> lines;

    std::string input;
    size_t maxLength{};
    while (std::getline(std::cin, input)) {
        lines.push_back(input);
        maxLength = std::max(maxLength, input.size());
    }

    for (size_t col{}; col < maxLength; ++col) {
        for (size_t i = lines.size(); i-- > 0; ) {
            output << (col < lines[i].size() ? lines[i][col] : ' ');
        }
        output << '\n';
    }

    std::cout << output.str();
}
