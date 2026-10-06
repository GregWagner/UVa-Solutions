/*
  * UVa 12279 - Emoogle Balance
  * Simple linear scan
  */
#include <iostream>
#include <sstream>

auto main() -> int
{
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int testCase {1};
    int n {};
    while (std::cin >> n && n != 0) {
        int balance {};
        for (int i {}; i < n; ++i) {
            int input {};
            std::cin >> input;
            balance += (input ? 1 : -1);
        }
        output << "Case " << testCase++ << ": " << balance << '\n';
    }
    std::cout << output.str();
}
