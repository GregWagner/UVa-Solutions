// 488 Triangle Wave
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    bool first{true};

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int amplitude, frequency;
        std::cin >> amplitude >> frequency;

        for (int i{}; i < frequency; ++i) {
            if (!first) {
                output << '\n';
            }
            first = false;

            int index{1};
            while (index <= amplitude) {
                for (int j{}; j < index; ++j) {
                    output << index;
                }
                output << '\n';
                ++index;
            }
            index -= 2;
            while (index > 0) {
                for (int j{}; j < index; ++j) {
                    output << index;
                }
                output << '\n';
                --index;
            }
        }
    }
    std::cout << output.str();
}
