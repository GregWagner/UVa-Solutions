#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int tea {};
    while (std::cin >> tea) {
        int answer {};
        for (int i {}; i < 5; ++i) {
            int guess {};
            std::cin >> guess;
            if (tea == guess) {
                ++answer;
            }
        }
        output << answer << '\n';
    }
    std::cout << output.str();
}
