// 337 Interpreting Control Sequences
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Global state variables
std::pair<int, int> cursor; // .first = row (y), .second = column (x)
bool insertMode;
char terminal[10][10];

// Function to write a character onto the terminal grid
auto writeOnTerminal(char c) -> void {
    if (insertMode) {
        // Shift characters to the right
        for (int i = 9; i > cursor.second; --i) {
            terminal[cursor.first][i] = terminal[cursor.first][i - 1];
        }
    }
    terminal[cursor.first][cursor.second] = c;
    if (cursor.second < 9) {
        cursor.second++;
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int caseNum{1};

    int numberOfInstructions;
    while (std::cin >> numberOfInstructions && numberOfInstructions != 0) {
        std::string line;
        std::getline(std::cin,
                     line); // Consume the remaining newline after reading n

        // Initialize terminal state for the new test case
        cursor = {0, 0};
        insertMode = false;
        memset(terminal, ' ', sizeof(terminal));

        for (int i{}; i < numberOfInstructions; ++i) {
            std::getline(std::cin, line);
            for (size_t j{}; j < line.length(); ++j) {
                if (line[j] == '^') {
                    ++j; // Move to the control command specifier
                    char cmd{line[j]};
                    switch (cmd) {
                    case 'b': // Beginning of line
                        cursor.second = 0;
                        break;
                    case 'c': // Clear screen
                        memset(terminal, ' ', sizeof(terminal));
                        break;
                    case 'd': // Down
                        if (cursor.first < 9)
                            cursor.first++;
                        break;
                    case 'e': // Erase to end of line
                        for (int k{cursor.second}; k < 10; ++k) {
                            terminal[cursor.first][k] = ' ';
                        }
                        break;
                    case 'h': // Home
                        cursor.first = 0;
                        cursor.second = 0;
                        break;
                    case 'i': // Insert mode on
                        insertMode = true;
                        break;
                    case 'l': // Left
                        if (cursor.second > 0)
                            cursor.second--;
                        break;
                    case 'o': // Overwrite mode on (Insert off)
                        insertMode = false;
                        break;
                    case 'r': // Right
                        if (cursor.second < 9)
                            cursor.second++;
                        break;
                    case 'u': // Up
                        if (cursor.first > 0)
                            cursor.first--;
                        break;
                    case '^': // Literal caret
                        writeOnTerminal('^');
                        break;
                    default: { // Absolute positioning ^r1r2
                        int r{cmd - '0'};
                        int c{line[++j] - '0'};
                        cursor.first = r;
                        cursor.second = c;
                        break;
                    }
                    }
                } else {
                    writeOnTerminal(line[j]);
                }
            }
        }

        // Output results
        output << "Case " << caseNum++ << "\n";
        output << "+----------+\n";
        for (int r = 0; r < 10; ++r) {
            output << "|";
            for (int c = 0; c < 10; ++c) {
                output << terminal[r][c];
            }
            output << "|\n";
        }
        output << "+----------+\n";
    }

    std::cout << output.str();
    return 0;
}
