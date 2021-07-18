#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

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
