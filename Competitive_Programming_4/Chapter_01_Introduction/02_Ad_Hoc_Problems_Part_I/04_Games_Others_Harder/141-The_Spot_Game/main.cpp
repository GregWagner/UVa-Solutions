/*
 * Problem 141 - The Spot Game
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstddef>

using namespace std;

struct State {
    int n;
    vector<vector<char>> grid; // or bitmask
    // for comparison
};

// Rotate grid 90 degrees clockwise
vector<vector<char>> rotate90(const vector<vector<char>>& grid, int n) {
    vector<vector<char>> rot(n, vector<char>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            rot[j][n - 1 - i] = grid[i][j];
        }
    }
    return rot;
}

// Check if two grids are identical
bool gridsEqual(const vector<vector<char>>& a, const vector<vector<char>>& b, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (a[i][j] != b[i][j]) return false;
        }
    }
    return true;
}

// Check if current grid state appeared before
// Returns true if this is a repeated state (under rotations)
bool isRepeated(const vector<vector<char>>& current, int n, 
                const vector<vector<vector<char>>>& history) {
    // Generate 4 rotations of current
    vector<vector<char>> r1 = current;
    for (int rot = 0; rot < 4; ++rot) {
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
vector<vector<char>> getRotation(const vector<vector<char>>& grid, int n, int k) {
    vector<vector<char>> r = grid;
    for (int i = 0; i < k; ++i) {
        r = rotate90(r, n);
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (cin >> n && n != 0) {
        vector<vector<char>> grid(n, vector<char>(n, 0));
        vector<vector<vector<char>>> history;
        // history stores states (we can store base or just store states; storing base is fine, 
        // we compare with rotations of current)
        
        bool gameOver = false;
        int winner = 0; // 0 draw/ongoing, 1 if P1 won, 2 if P2 won
        int winMove = 0;
        
        // Max moves possible: 2*n*n (each cell can be filled then emptied, but practically)
        int maxMoves = n * n * 2;
        for (int move = 1; move <= maxMoves && !gameOver; ++move) {
            int x, y;
            char op;
            cin >> x >> y >> op;
            // Convert to 0-based
            x--;
            y--;
            // Apply move
            if (op == '+') {
                grid[x][y] = 1;
            } else { // '-'
                grid[x][y] = 0;
            }
            // Check if this state is repeated
            // Save current state to history before? Or check - we need to compare against previous states
            // The state just created: check if it appeared before
            // Generate rotations of current and compare with all history
            bool repeated = false;
            // Check against history with 4 rotations
            {
                vector<vector<char>> r = grid;
                for (int rot = 0; rot < 4 && !repeated; ++rot) {
                    // compare r with all history
                    for (const auto& hist : history) {
                        // compare
                        bool equal = true;
                        // fast compare
                        for (int i = 0; i < n && equal; ++i) {
                            for (int j = 0; j < n && equal; ++j) {
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
                        // rotate r
                        vector<vector<char>> rnew(n, vector<char>(n, 0));
                        for (int i = 0; i < n; ++i) {
                            for (int j = 0; j < n; ++j) {
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
                // Don't add current state to history? The state appeared before
                // Game ends, remaining input for this test case continues to be read?
                // But we need to consume remaining moves until? No wait - the game ended,
                // but the input stream still has moves for this test case that come after.
                // We must read and discard them until we get to next test case or until
                // we've consumed all moves that were in input for this game?
                // But how many more moves follow? The problem states "the input for each test case
                // is: the size n, followed by 2n lines, each with x y c (or until end of file)."
                // Or sometimes game ends early. We need to read remaining moves of this test case.
                // But we don't know how many - we need to read until we would have consumed 2*n*n
                // total moves max? Or just keep reading until? Maybe read moves until end of test
                // case is determined by structure - but easier to just consume remaining
                // moves for this game: total moves played so far in terms of input consumed
                // is move (we just consumed this move). We need to consume (total moves expected - move)
                // more, but if game ended early, we still consume them from input.
                int remaining = maxMoves - move;
                for (int i = 0; i < remaining; ++i) {
                    int tx, ty;
                    char tc;
                    cin >> tx >> ty >> tc;
                }
                break;
            }
            
            // Check if board is full (all cells are 1) - no more legal moves?
            // A player can remove spots (-) if occupied, so board can never be "full" in terms
            // of having no moves except not possible? You can always remove if there are spots,
            // or add if empty. So legal moves always exist unless? No - you can do anything
            // as long as you place on empty or remove from occupied. So always legal moves
            // exist as long as game continues. The draw occurs if the board becomes full
            // of spots and forms a configuration that never repeated before? Let us look up:
            // "If a player cannot make a move (because the board is in a configuration where no more
            // spots can be placed and all spots that are on the board cannot be removed without
            // creating a position that has occurred before), the player loses. The game is a draw
            // if the board fills up (all cells have spots on them) and neither player loses."
            // Or more precisely from UVa: "A player loses the game if after their move, the board
            // position (the pattern) is identical to one that previously existed. The game ends in a
            // draw if the entire board is filled and no duplicate position has occurred."
            // Also you can place on empty or remove from occupied - so you can create/destroy.
            // The draw is when board is completely filled (all 1s) with no repetition - then next
            // player cannot place anything new? Or game ends. The problem states "The game ends in a
            // draw if the entire board is filled and no duplicate position has occurred."
            // So when all cells are filled (all spots on), if that position never occurred before,
            // game is draw.
            bool isFull = true;
            for (int i = 0; i < n && isFull; ++i) {
                for (int j = 0; j < n && isFull; ++j) {
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
                int remaining = maxMoves - move;
                for (int i = 0; i < remaining; ++i) {
                    int tx, ty;
                    char tc;
                    cin >> tx >> ty >> tc;
                }
                break;
            }
            
            // Save current state to history
            history.push_back(grid);
        }
        
        // Output result
        if (winner == 1) {
            cout << "Player 1 wins on move " << winMove << "\n";
        } else if (winner == 2) {
            cout << "Player 2 wins on move " << winMove << "\n";
        } else {
            cout << "Draw\n";
        }
    }
    
    return 0;
}