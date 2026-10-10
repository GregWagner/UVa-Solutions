/*
 * 10443 Rock, Scissors, Paper
 */
#include <iostream>
#include <sstream>
#include <vector>

auto beats(char a, char b) -> bool {
    return (((a == 'R') && (b == 'S')) || ((a == 'S') && (b == 'P')) ||
            ((a == 'P') && (b == 'R')));
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases{};
    std::cin >> testCases;

    while (testCases--) {
        int rows, cols, numberOfDays;
        std::cin >> rows >> cols >> numberOfDays;
        std::vector<std::vector<char>> board(rows, std::vector<char>());
        for (int i{}; i < rows; ++i) {
            std::string line;
            std::cin >> line;
            board[i].assign(line.begin(), line.end());
        }

        // day simulation
        auto nextBoard = board;

        // used to look at a cells orthogonal neighbors
        const int dirR[] = {-1, 1, 0, 0};
        const int dirC[] = {0, 0, -1, 1};

        for (int day{}; day < numberOfDays; ++day) {
            for (int i{}; i < rows; ++i) {
                for (int j{}; j < cols; ++j) {
                    // default action is stays the same
                    nextBoard[i][j] = board[i][j];
                    for (int k{}; k < 4; ++k) {
                        int nextI = i + dirR[k];
                        int nextJ = j + dirC[k];

                        // check for out of bounds
                        if ((nextI < 0) || (nextI >= rows) || (nextJ < 0) ||
                            (nextJ >= cols)) {
                            continue;
                        }
                        if (beats(board[nextI][nextJ], board[i][j])) {
                            nextBoard[i][j] = board[nextI][nextJ];
                        }
                    }
                }
            }
            board.swap(nextBoard);
        }
        // display the updated board
        for (int i{}; i < rows; ++i) {
            for (int j{}; j < cols; ++j) {
                output << board[i][j];
            }
            output << '\n';
        }
        if (testCases) output << '\n'; // empty line between cases, not after the last
    }
    std::cout << output.str();
}
