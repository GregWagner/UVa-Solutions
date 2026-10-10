/*
 * 10813 Traditional Bingo
 */
#include <iostream>
#include <sstream>
#include <utility>
#include <vector>

bool hasBingo(const std::vector<std::vector<bool>>& marked) {
    // rows
    for (int r{}; r < 5; ++r) {
        bool complete = true;
        for (int c{}; c < 5; ++c) {
            if (!marked[r][c]) {
                complete = false;
                break;
            }
        }
        if (complete) {
            return true;
        }
    }

    // columns
    for (int c{}; c < 5; ++c) {
        bool complete = true;
        for (int r{}; r < 5; ++r) {
            if (!marked[r][c]) {
                complete = false;
                break;
            }
        }
        if (complete) {
            return true;
        }
    }

    // main diagonal: (0,0) (1,1) (2,2) (3,3) (4,4)
    {
        bool complete = true;
        for (int r{}; r < 5; ++r) {
            if (!marked[r][r]) {
                complete = false;
                break;
            }
        }
        if (complete) {
            return true;
        }
    }

    // anti-diagonal: (0,4) (1,3) (2,2) (3,1) (4,0)
    {
        bool complete = true;
        for (int r{}; r < 5; ++r) {
            if (!marked[r][4 - r]) {
                complete = false;
                break;
            }
        }
        if (complete) {
            return true;
        }
    }

    return false;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases{};
    std::cin >> testCases;
    while (testCases--) {
        std::vector<std::vector<int>> grid(5, std::vector<int>(5, 0));
        std::vector<std::vector<bool>> marked(5, std::vector<bool>(5, false));

        // setup the initial bingo card
        for (int row{}; row < 5; ++row) {
            if (row != 2) {
                for (int col{}; col < 5; ++col) {
                    int input{};
                    std::cin >> input;
                    grid[row][col] = input;
                }
            } else {
                for (int col{}; col < 5; ++col) {
                    if (col == 2) {
                        grid[row][col] = 99;
                        marked[row][col] = true;
                        continue;
                    }
                    int input{};
                    std::cin >> input;
                    grid[row][col] = input;
                }
            }
        }

        // add a small lookup from value -> cell, after the grid is filled
        std::vector<std::pair<int, int>> where(76, {-1, -1});
        for (int row{}; row < 5; ++row) {
            for (int col{}; col < 5; ++col) {
                int value = grid[row][col];
                if (value != 99) {
                    where[value] = {row, col};
                }
            }
        }

        // read in the numbers that are called
        int bingoAt{};
        for (int i{1}; i <= 75; ++i) {
            int num{};
            std::cin >> num;
            auto [r, c] = where[num];

            if (r != -1) {
                marked[r][c] = true;
                if (bingoAt == 0 && hasBingo(marked)) {
                    bingoAt = i;
                }
            }
        }
        output << "BINGO after " << bingoAt << " numbers announced\n";
    }

    std::cout << output.str();
}
