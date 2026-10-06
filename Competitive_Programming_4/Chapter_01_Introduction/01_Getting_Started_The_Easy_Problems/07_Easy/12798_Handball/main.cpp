#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int numberOfPlayers {};
    int numberOfMatches {};
    while (std::cin >> numberOfPlayers >> numberOfMatches) {
        int count {};
        for (int i {}; i < numberOfPlayers; ++i) {
            bool zero {false};
            for (int j {}; j < numberOfMatches; ++j) {
                int score;
                std::cin >> score;
                if (score == 0) {
                    zero = true;
                }
            }
            if (!zero) {
                ++count;
            }
        }
        output << count << '\n';
    }
    std::cout << output.str();
}
