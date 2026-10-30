#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int numberOfPlayers, numberOfRounds;
    while (std::cin >> numberOfPlayers >> numberOfRounds) {
        if (numberOfPlayers == 0 && numberOfRounds == 0) {
            break;
        }

        std::vector<int> scores(numberOfPlayers + 1, 0);

        int totalTurns = numberOfPlayers * numberOfRounds;
        for (int i = 0; i < totalTurns; ++i) {
            int points;
            std::cin >> points;
            int playerId = (i % numberOfPlayers) + 1;
            scores[playerId] += points;
        }

        int maxScore = -1;
        int winningPlayer = 1;
        for (int player = 1; player <= numberOfPlayers; ++player) {
            if (scores[player] >= maxScore) {
                maxScore = scores[player];
                winningPlayer = player;
            }
        }
        output << winningPlayer << '\n';
    }
    std::cout << output.str();
}
