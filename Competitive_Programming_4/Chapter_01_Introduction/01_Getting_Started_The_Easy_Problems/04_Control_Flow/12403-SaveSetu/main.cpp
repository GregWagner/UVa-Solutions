#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int n {};
    std::cin >> n;
    int money {};
    while (n--) {
        std::string input;
        std::cin >> input;
        if (input == "report") {
            output << money << '\n';
        } else {
            int donation {};
            std::cin >> donation;
            money += donation;
        }
    }
    std::cout << output.str();
}
