/*
 * 10903 - Rock Paper Scissors Tournament
 */
#include <iomanip>
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

auto keepScore(std::vector<std::pair<int, int>>& score, int winner, int loser)
    -> void {
    score[winner].first++;
    score[loser].second++; // lose
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int numberOfPlayers{}, numberOfGames{};
    bool printedCase{false};
    output << std::fixed << std::setprecision(3);
    while (std::cin >> numberOfPlayers >> numberOfGames &&
           numberOfPlayers != 0) {
        if (printedCase) {
            output << '\n';
        }
        printedCase = true;

        std::vector<std::pair<int, int>> score(numberOfPlayers + 1, {0, 0});

        int games{numberOfGames * numberOfPlayers * (numberOfPlayers - 1) / 2};
        while (games--) {
            int playerA{}, playerB{};
            std::string playerAchoice{}, playerBchoice{};
            std::cin >> playerA >> playerAchoice >> playerB >> playerBchoice;

            if (playerAchoice == "rock" && playerBchoice == "scissors") {
                keepScore(score, playerA, playerB);
            } else if (playerAchoice == "scissors" &&
                       playerBchoice == "paper") {
                keepScore(score, playerA, playerB);
            } else if (playerAchoice == "paper" && playerBchoice == "rock") {
                keepScore(score, playerA, playerB);
            } else if (playerBchoice == "rock" && playerAchoice == "scissors") {
                keepScore(score, playerB, playerA);
            } else if (playerBchoice == "scissors" &&
                       playerAchoice == "paper") {
                keepScore(score, playerB, playerA);
            } else if (playerBchoice == "paper" && playerAchoice == "rock") {
                keepScore(score, playerB, playerA);
            }
        }
        for (int player{1}; player <= numberOfPlayers; ++player) {
            int wins{score[player].first};
            int losses{score[player].second};
            if (wins + losses == 0) {
                output << "-\n";
            } else {
                output << static_cast<double>(wins) / (wins + losses) << '\n';
            }
        }
    }
    std::cout << output.str();
}
