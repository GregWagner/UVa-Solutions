// 537 - Artificial Intelligence
#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testNum{1};
    int testCases{};
    std::cin >> testCases;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (testCases--) {
        double P{}, I{}, U{};
        bool pSet{}, iSet{}, uSet{};
        std::string sentence;
        std::getline(std::cin, sentence);
        for (size_t i{1}; i < sentence.size(); ++i) {
            if (sentence[i] == '=') {
                size_t start = i + 1;
                char* endptr = nullptr;
                double value = std::strtod(sentence.c_str() + start, &endptr);
                size_t end = static_cast<size_t>(endptr - sentence.c_str());

                // Check for unit prefix
                if (end < sentence.length()) {
                    char prefix = sentence[end];
                    if (prefix == 'm') {
                        value *= 1e-3;
                    } else if (prefix == 'k') {
                        value *= 1e3;
                    } else if (prefix == 'M') {
                        value *= 1e6;
                    }
                }
                if (sentence[i - 1] == 'P') {
                    pSet = true;
                    P = value;
                } else if (sentence[i - 1] == 'I') {
                    I = value;
                    iSet = true;
                } else if (sentence[i - 1] == 'U') {
                    U = value;
                    uSet = true;
                }
            }
        }
        output << "Problem #" << testNum++ << "\n"
               << std::fixed << std::setprecision(2);
        if (!pSet) {
            output << "P=" << U * I << "W\n";
        } else if (!iSet) {
            output << "I=" << P / U << "A\n";
        } else if (!uSet) {
            output << "U=" << P / I << "V\n";
        }
        output << '\n';
    }

    std::cout << output.str();
}
