// 447 - Population Explosion
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const int SIZE{20};
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int countNeighbors(const std::vector<std::string>& grid, int r, int c) {
    int count{};
    for (int i{}; i < 8; ++i) {
        int x = r + dx[i];
        int y = c + dy[i];
        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
            if (grid[x][y] == 'O') {
                ++count;
            }
        }
    }
    return count;
}

std::vector<std::string> step(const std::vector<std::string>& grid) {
    std::vector<std::string> next(SIZE, std::string(SIZE, ' '));
    for (int r{}; r < SIZE; ++r) {
        for (int c{}; c < SIZE; ++c) {
            int n = countNeighbors(grid, r, c);
            if (grid[r][c] == 'O') {
                if (n == 2 || n == 3)
                    next[r][c] = 'O';
            } else {
                if (n == 3)
                    next[r][c] = 'O';
            }
        }
    }
    return next;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    // read number of cases
    // skip leading empty lines
    std::vector<std::string> lines;
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }

    size_t idx{};
    while (idx < lines.size() &&
           lines[idx].find_first_not_of(" \t\r\n") == std::string::npos)
        ++idx;
    if (idx >= lines.size())
        return 0;
    int testCases = std::stoi(lines[idx++]);

    std::ostringstream output;
    const std::string border(20, '*');

    for (int caseNumber{}; caseNumber < testCases; ++caseNumber) {
        // skip blank lines
        while (idx < lines.size() &&
               lines[idx].find_first_not_of(" \t\r\n") == std::string::npos)
            ++idx;
        if (idx >= lines.size())
            break;
        int years = std::stoi(lines[idx++]);

        std::vector<std::string> grid(SIZE, std::string(SIZE, ' '));
        // read coordinates until blank line
        while (idx < lines.size() &&
               lines[idx].find_first_not_of(" \t\r\n") != std::string::npos) {
            std::istringstream iss(lines[idx]);
            int r, c;
            if (iss >> r >> c) {
                if (r >= 1 && r <= SIZE && c >= 1 && c <= SIZE) {
                    grid[r - 1][c - 1] = 'O';
                }
            }
            ++idx;
        }

        if (caseNumber > 0) {
            output << '\n';
        }
        output << border << '\n';
        std::vector<std::string> cur = grid;
        for (int y{}; y < years; ++y) {
            if (y > 0) {
                cur = step(cur);
            }
            for (int r{}; r < SIZE; ++r) {
                output << cur[r] << '\n';
            }
            output << border << '\n';
        }
    }
    std::cout << output.str();
}