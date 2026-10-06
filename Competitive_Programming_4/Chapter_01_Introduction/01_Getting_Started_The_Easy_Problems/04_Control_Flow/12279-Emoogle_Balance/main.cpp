#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int test_case {};

    int n {};
    while (std::cin >> n && n != 0) {
        int balance {};
        for (int i {}; i < n; ++i) {
            int input {};
            std::cin >> input;
            input == 0 ? --balance : ++balance;
        }
        std::cout << "Case " << ++test_case << ": " << balance << '\n';
    }

    std::cout << output.str();
}
