// 11743 Credit Check
#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int sum{};
        for (int i{}; i < 4; ++i) {
            std::string input;
            std::cin >> input;
            for (int j{}; j < 4; ++j) {
                int number{input[j] - '0'};
                if (j % 2 == 0) {
                    number *= 2;
                    while (number >= 10) {
                        sum += number % 10;
                        number /= 10;
                    }
                    sum += number;
                } else {
                    sum += number;
                }
            }
        }
        output << (sum % 10 == 0 ? "Valid\n" : "Invalid\n");
    }
    std::cout << output.str();
}
