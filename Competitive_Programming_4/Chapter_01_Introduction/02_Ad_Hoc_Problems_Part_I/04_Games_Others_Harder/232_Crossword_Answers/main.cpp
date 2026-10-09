/*
 * 232 Crossword Answers
 */
#include <iomanip>
#include <iostream>
#include <sstream>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int puzzleNumber{1};
    int r{};
    while (std::cin >> r && r != 0) {
        int c{};
        std::cin >> c;

        if (puzzleNumber > 1) {
            output << '\n';
        }
        output << "puzzle #" << puzzleNumber++ << ":\n";

        // store the grid rows
        std::vector<std::string> rows;
        rows.reserve(r);

        for (int row{}; row < r; ++row) {
            std::string input;
            std::cin >> input;
            rows.push_back(input);
        }

        // assign clue numbers
        int counter{1};
        std::vector<std::vector<int>> numbers(r, std::vector<int>(c, 0));
        for (int row{}; row < r; ++row) {
            for (int col{}; col < c; ++col) {
                char ch = rows[row][col];
                if (ch == '*') {
                    continue;
                }
                auto startAcross = ((col == 0) || (rows[row][col - 1] == '*'));
                auto startDown = ((row == 0) || (rows[row - 1][col] == '*'));
                if (startAcross || startDown) {
                    numbers[row][col] = counter++;
                }
            }
        }

        //  extract ACROSS words
        output << "Across\n";
        for (int row{}; row < r; ++row) {
            for (int col{}; col < c; ++col) {
                if (numbers[row][col] != 0 &&
                    (col == 0 || rows[row][col - 1] == '*')) {
                    std::string word;
                    for (int index{col};
                         index < c && rows[row][index] != '*';
                         ++index) {
                        word += rows[row][index];
                    }
                    output << std::setw(3) << numbers[row][col] << "."
                           << word << '\n';
                }
            }
        }
        //  extract DOWN words
        output << "Down\n";
        for (int row{}; row < r; ++row) {
            for (int col{}; col < c; ++col) {
                if (numbers[row][col] != 0 &&
                    (row == 0 || rows[row - 1][col] == '*')) {
                    std::string word;
                    for (int index{row};
                         index < r && rows[index][col] != '*';
                         ++index) {
                        word += rows[index][col];
                    }
                    output << std::setw(3) << numbers[row][col] << "."
                           << word << '\n';
                }
            }
        }
    }
    std::cout << output.str();
}
