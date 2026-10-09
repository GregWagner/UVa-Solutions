/*
 * Problem 141 - The Spot Game
 */
#include <iostream>
#include <vector>

struct State {
    int n;
    std::vector<std::vector<char>> grid;
};

// Rotate grid 90 degrees clockwise
auto rotate90(const std::vector<std::vector<char>>& grid, int n)
    -> std::vector<std::vector<char>> {
    std::vector<std::vector<char>> rot(n, std::vector<char>(n, char{0}));
    for (int i{}; i < n; ++i) {
        for (int j{}; j < n; ++j) {
            rot[j][n - 1 - i] = grid[i][j];
        }
    }
    return rot;
}

// Check if two grids are identical
auto gridsEqual(const std::vector<std::vector<char>>& a,
                const std::vector<std::vector<char>>& b, int n) -> bool {
    for (int i{}; i < n; ++i) {
        for (int j{}; j < n; ++j) {
            if (a[i][j] != b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Check if current grid state appeared before
// Returns true if this is a repeated state (under rotations)
auto isRepeated(const std::vector<std::vector<char>>& current, int n,
                const std::vector<std::vector<std::vector<char>>>& history)
    -> bool {
    // Generate 4 rotations of current
    std::vector<std::vector<char>> r1 = current;
    for (int rot{}; rot < 4; ++rot) {
        // check against all history states
        for (const auto& histState : history) {
            if (gridsEqual(r1, histState, n)) {
                return true;
            }
        }
        if (rot < 3) {
            r1 = rotate90(r1, n);
        }
    }
    return false;
}

// Get rotation of grid
auto getRotation(const std::vector<std::vector<char>>& grid, int n, int k)
    -> std::vector<std::vector<char>> {
    std::vector<std::vector<char>> r = grid;
    for (int i{}; i < k; ++i) {
        r = rotate90(r, n);
    }
    return r;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    while (std::cin >> n && n != 0) {
        std::vector<std::vector<char>> grid(n, std::vector<char>(n, char{0}));
        std::vector<std::vector<std::vector<char>>> history{};
        // history stores states (we can store base or just store states;
        // storing base is fine, we compare with rotations of current)

        bool gameOver{};
        int winner{}; // 0 draw/ongoing, 1 if P1 won, 2 if P2 won
        int winMove{};

        // Max moves possible: 2*n*n (each cell can be filled then emptied, but
        // practically)
        int maxMoves{2 * n};
        for (int move = 1; move <= maxMoves && !gameOver; ++move) {
            int x, y;
            char op;
            std::cin >> x >> y >> op;
            // Convert to 0-based
            x--;
            y--;
            // Apply move
            if (op == '+') {
                grid[x][y] = 1;
            } else { // '-'
                grid[x][y] = 0;
            }
            // Check if this state is repeated (rotations by 90 degrees)
            bool repeated = false;
            {
                std::vector<std::vector<char>> r{grid};
                for (int rot{}; rot < 4 && !repeated; ++rot) {
                    for (const auto& hist : history) {
                        bool equal = true;
                        for (int i{}; i < n && equal; ++i) {
                            for (int j{}; j < n && equal; ++j) {
                                if (r[i][j] != hist[i][j]) {
                                    equal = false;
                                }
                            }
                        }
                        if (equal) {
                            repeated = true;
                            break;
                        }
                    }
                    if (rot < 3) {
                        std::vector<std::vector<char>> rnew(
                            n, std::vector<char>(n, char{0}));
                        for (int i{}; i < n; ++i) {
                            for (int j{}; j < n; ++j) {
                                rnew[j][n - 1 - i] = r[i][j];
                            }
                        }
                        r = std::move(rnew);
                    }
                }
            }

            if (repeated) {
                // Current player loses - other player wins
                if (move % 2 == 1) {
                    // P1 made the move and created repeat - P2 wins
                    winner = 2;
                } else {
                    // P2 made the move - P1 wins
                    winner = 1;
                }
                winMove = move;
                gameOver = true;
                int remaining{maxMoves - move};
                for (int i{}; i < remaining; ++i) {
                    int tx, ty;
                    char tc;
                    std::cin >> tx >> ty >> tc;
                }
                break;
            }

            bool isFull{true};
            for (int i{}; i < n && isFull; ++i) {
                for (int j{}; j < n && isFull; ++j) {
                    if (grid[i][j] == 0) {
                        isFull = false;
                    }
                }
            }
            if (isFull) {
                // Board is full and no repetition occurred (we just checked)
                winner = 0;
                gameOver = true;
                winMove = move;
                // Consume remaining moves
                int remaining{maxMoves - move};
                for (int i{}; i < remaining; ++i) {
                    int tx, ty;
                    char tc;
                    std::cin >> tx >> ty >> tc;
                }
                break;
            }

            // Save current state to history
            history.push_back(grid);
        }

        // Output result
        if (winner == 1) {
            std::cout << "Player 1 wins on move " << winMove << "\n";
        } else if (winner == 2) {
            std::cout << "Player 2 wins on move " << winMove << "\n";
        } else {
            std::cout << "Draw\n";
        }
    }
}
