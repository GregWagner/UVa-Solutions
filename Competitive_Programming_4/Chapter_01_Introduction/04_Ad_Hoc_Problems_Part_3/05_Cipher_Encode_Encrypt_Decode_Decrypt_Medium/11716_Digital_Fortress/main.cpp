// 11716 - Digital Fortress
#include <cmath>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    while (testCases--) {
        std::string input;
        std::getline(std::cin, input);
        if (!input.empty() && input.back() == '\r') {
            input.pop_back();
        }

        int n = static_cast<int>(std::sqrt(static_cast<double>(input.size())));
        if (n * n != static_cast<int>(input.size())) {
            output << "INVALID\n";
            continue;
        }

        // Cipher text is stored row major at input[i * n + j];
        // reading it column major means j outer, then i inner.
        for (int j{}; j < n; ++j) {
            for (int i{}; i < n; ++i) {
                output << input[i * n + j];
            }
        }
        output << '\n';
    }

    std::cout << output.str();
}
