/*
 * 10363 - Tic Tac Toe
 */
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    while (testCases--) {
        int xCount{}, oCount{};
        int board[3][3];
        for (int row{}; row < 3; ++row) {
            std::string line;
            std::cin >> line;
            for (int index{}; index < 3; ++index) {
                char letter{line[index]};
                if (letter == 'X') {
                    ++xCount;
                    board[row][index] = 1;
                } else if (letter == 'O') {
                    ++oCount;
                    board[row][index] = -1;
                } else {
                    board[row][index] = 0;
                }
            }
        }

        bool xWin{}, oWin{};
        auto scan = [&](int a, int b, int c) {
            if (a != 0 && a == b && b == c) {
                if (a == 1) {
                    xWin = true;
                } else {
                    oWin = true;
                }
            }
        };

        scan(board[0][0], board[0][1], board[0][2]); // row 0
        scan(board[1][0], board[1][1], board[1][2]); // row 1
        scan(board[2][0], board[2][1], board[2][2]); // row 2
        scan(board[0][0], board[1][0], board[2][0]); // col 0
        scan(board[0][1], board[1][1], board[2][1]); // col 1
        scan(board[0][2], board[1][2], board[2][2]); // col 2
        scan(board[0][0], board[1][1], board[2][2]); // diagonal ↘
        scan(board[0][2], board[1][1], board[2][0]); // diagonal ↙

        auto valid = ((xCount - oCount == 0) || (xCount - oCount == 1)) &&
                     !(xWin && oWin) && (!xWin || xCount == oCount + 1) &&
                     (!oWin || xCount == oCount);

        output << (valid ? "yes\n" : "no\n");
    }
    std::cout << output.str();
}
