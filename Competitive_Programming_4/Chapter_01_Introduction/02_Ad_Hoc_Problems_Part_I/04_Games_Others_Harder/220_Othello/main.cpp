/*
 * 220 Othello
 */
#include <array>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// ----- data models -------------------------------------------------------

// board[r][c] is '-', 'B' or 'W'; stored 0-indexed, but UVa coords are 1-indexed.
using Board = std::array<std::array<char, 8>, 8>;

// The 8 directions: N, NW, W, SW, S, SE, E, NE.
constexpr int DR[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
constexpr int DC[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

inline char opponent(char piece) { return piece == 'B' ? 'W' : 'B'; }

// ----- rules -------------------------------------------------------------

// True if player 'p' may place on the empty cell (r,c): at least one of the
// 8 rays must run over >=1 opponent pieces and terminate at one of p's pieces.
bool isLegal(const Board &board, char p, int r, int c) {
    if (board[r][c] != '-') return false;
    for (int d = 0; d < 8; ++d) {
        int rr = r + DR[d];
        int cc = c + DC[d];
        int flipped = 0;
        while (rr >= 0 && rr < 8 && cc >= 0 && cc < 8 && board[rr][cc] == opponent(p)) {
            rr += DR[d];
            cc += DC[d];
            ++flipped;
        }
        if (flipped > 0 && rr >= 0 && rr < 8 && cc >= 0 && cc < 8 && board[rr][cc] == p) {
            return true;
        }
    }
    return false;
}

bool hasLegalMove(const Board &board, char p) {
    for (int r = 0; r < 8; ++r) {
        for (int c = 0; c < 8; ++c) {
            if (isLegal(board, p, r, c)) return true;
        }
    }
    return false;
}

// Place p on (r,c) and flip every opponent run bracketed by the new piece.
void applyMove(Board &board, char p, int r, int c) {
    board[r][c] = p;
    for (int d = 0; d < 8; ++d) {
        int rr = r + DR[d];
        int cc = c + DC[d];
        while (rr >= 0 && rr < 8 && cc >= 0 && cc < 8 && board[rr][cc] == opponent(p)) {
            rr += DR[d];
            cc += DC[d];
        }
        if (rr >= 0 && rr < 8 && cc >= 0 && cc < 8 && board[rr][cc] == p) {
            // Walk back from the cell next to (r,c) up to (rr,cc), flipping.
            for (int fr = r + DR[d], fc = c + DC[d]; fr != rr || fc != cc; fr += DR[d], fc += DC[d]) {
                board[fr][fc] = p;
            }
        }
    }
}

// ----- input handling ----------------------------------------------------

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int games{};
    std::cin >> games;
    for (int g = 0; g < games; ++g) {
        Board board{};
        for (auto &row : board) {
            for (char &cell : row) {
                std::cin >> cell;  // one non-whitespace char per cell
            }
        }

        char cur{};
        std::cin >> cur;  // player to move: 'W' or 'B'

        std::string cmd{};
        while (std::cin >> cmd && cmd[0] != 'Q') {
            if (cmd[0] == 'L') {
                bool any = false;
                for (int r = 0; r < 8; ++r) {
                    for (int c = 0; c < 8; ++c) {
                        if (isLegal(board, cur, r, c)) {
                            if (any) output << ' ';
                            output << '(' << (r + 1) << ',' << (c + 1) << ')';
                            any = true;
                        }
                    }
                }
                if (!any) output << "No legal move.";
                output << '\n';
            } else if (cmd[0] == 'M') {
                int r = cmd[1] - '0';
                int c = cmd[2] - '0';
                if (!hasLegalMove(board, cur)) cur = opponent(cur);  // pass rule
                applyMove(board, cur, r - 1, c - 1);
                int black = 0;
                int white = 0;
                for (const auto &row : board) {
                    for (char cell : row) {
                        if (cell == 'B') ++black;
                        else if (cell == 'W') ++white;
                    }
                }
                output << "Black - " << std::setw(2) << black
                       << " White - " << std::setw(2) << white << '\n';
                cur = opponent(cur);
            }
        }

        // Q: print the final board. A single blank line separates games, so
        // add one only when another game follows (never after the last one).
        for (const auto &row : board) {
            for (char cell : row) output << cell;
            output << '\n';
        }
        if (g + 1 < games) output << '\n';
    }

    std::cout << output.str();
}
