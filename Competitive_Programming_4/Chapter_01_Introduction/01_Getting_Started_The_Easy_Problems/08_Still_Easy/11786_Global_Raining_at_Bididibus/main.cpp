#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int height {};
    bool fillling {};
    int testCases {};
    std::cin >> testCases;
    while (testCases--) {
        std::string input;
        std::cin >> input;
        for (const auto & c : input) {
            if (c == '/') {
                ++height;
            } else if (c == '\\') {

            } else {

            }
        }
    }
    std::cout << output.str();
}
