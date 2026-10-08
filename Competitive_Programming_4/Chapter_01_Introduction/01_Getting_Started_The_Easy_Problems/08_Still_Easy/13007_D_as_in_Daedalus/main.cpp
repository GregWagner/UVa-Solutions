#include <iostream>
#include <sstream>
#include <algorithm>
#include <array>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::ostringstream output;

    const std::array<int, 5> cards{10000, 1000, 100, 10, 1};
    int numberOfPlayers{}, numberOfRounds{};
    while (std::cin >> numberOfPlayers >> numberOfRounds) {
        long long totalExtra = 0;
        while (numberOfRounds--) {
            int bank{}, myCard{};
            std::cin >> bank >> myCard;
            int sumOthers = 0;
            for (int i = 1; i < numberOfPlayers; ++i) {
                int playerCard{};
                std::cin >> playerCard;
                sumOthers += playerCard;
            }
            // compute actual points
            int actual = 0;
            if (sumOthers + myCard <= bank) {
                actual = myCard;
            }
            // compute best possible
            int best = 0;
            for (const auto &c : cards) {
                if (sumOthers + c <= bank) {
                    best = std::max(best, c);
                }
            }
            totalExtra += (best - actual);
        }
        output << totalExtra << '\n';
    }
    std::cout << output.str();
}
