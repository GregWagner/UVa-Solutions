/*
 * 12279 Emoogle Balance
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCase {};
    int numberOfEvents {};
    while (std::cin >> numberOfEvents && numberOfEvents != 0) {
        int score {};
        for (int i {}; i < numberOfEvents; ++i) {
            int input {};
            std::cin >> input;
            input == 0 ? --score : ++score;
        }
        output << "Case " << ++testCase << ": " << score << '\n';
    }
    std::cout << output.str();
}
