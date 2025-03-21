/*
 * Problem 11459 - Snakes and Ladders
 */
#include <iostream>
#include <sstream>
#include <vector>

int board[110];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        bool won {};
        for (int i {}; i < 110; ++i) {
            board[i] = 0;
        }
        int players, snakesorladders, rolls;
        std::cin >> players >> snakesorladders >> rolls;
        for (int i {}; i < snakesorladders; ++i) {
            int start, end;
            std::cin >> start >> end;
            board[start] = end;
        }
        std::vector<int> positions(players);
        for (int i {}; i < players; ++i) {
            positions[i] = 1;
        }
        int player {};
        for (int i {}; i < rolls; ++i) {
            int die;
            std::cin >> die;
            if (!won) {
                positions[player] += die;
                if (board[positions[player]] != 0) {
                    positions[player] = board[positions[player]];
                }
                if (positions[player] >= 100) {
                    positions[player] = 100;
                    won = true;
                }
            }
            ++player;
            player %= players;
        }
        for (int i {}; i < players; ++i) {
            std::cout << "Position of player " << i + 1
                << " is " << positions[i] << ".\n";
        }
    }
    std::cout << output.str();
}
