/*
 * 227 - Puzzle
 */
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

char board[5][5];

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    std::string line;
    int puzzle{1};
    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            continue; // tolerate stray blank lines between puzzles
        }
        if (line[0] == 'Z') {
            break; // terminating line: end of input
        }

        // The first row is already in `line`; read the other four.
        std::string rows[5];
        rows[0] = line;
        for (int r{1}; r < 5; ++r) {
            std::getline(std::cin, rows[r]);
        }

        // Copy the rows into the board and locate the blank cell.
        std::pair<int, int> empty{-1, -1};
        for (int r{}; r < 5; ++r) {
            for (int c{}; c < 5; ++c) {
                board[r][c] =
                    (c < static_cast<int>(rows[r].size())) ? rows[r][c] : ' ';
                if (board[r][c] == ' ') {
                    empty = {r, c};
                }
            }
        }

        // Read this puzzle's move sequence, which may span several lines,
        // stopping at the terminating '0'.
        std::string moves;
        bool done{};
        while (!done && std::getline(std::cin, line)) {
            for (char c : line) {
                if (c == '0') {
                    done = true;
                    break;
                }
                if (c != ' ' && c != '\r') {
                    moves.push_back(c);
                }
            }
        }

        // Apply the moves from the blank's current position.
        int r{empty.first};
        int c{empty.second};
        bool valid{true};
        for (char move : moves) {
            int nr{r}, nc{c};
            switch (move) {
            case 'A':
                --nr;
                break; // blank up
            case 'B':
                ++nr;
                break; // blank down
            case 'L':
                --nc;
                break; // blank left
            case 'R':
                ++nc;
                break; // blank right
            default:
                valid = false;
                break;
            }
            // Check the boundary (also catches unknown commands).
            if (!valid || nr < 0 || nr > 4 || nc < 0 || nc > 4) {
                valid = false; // the blank would leave the board
                break;
            }
            std::swap(board[r][c], board[nr][nc]);
            r = nr;
            c = nc;
        }

        if (puzzle > 1) {
            output << '\n'; // blank line between puzzles
        }
        output << "Puzzle #" << puzzle << ":\n";
        if (!valid) {
            output << "This puzzle has no final configuration.\n";
        } else {
            for (int i{}; i < 5; ++i) {
                for (int j{}; j < 4; ++j) {
                    output << board[i][j] << ' ';
                }
                output << board[i][4] << '\n';
            }
        }

        ++puzzle;
    }
    std::cout << output.str();
}
