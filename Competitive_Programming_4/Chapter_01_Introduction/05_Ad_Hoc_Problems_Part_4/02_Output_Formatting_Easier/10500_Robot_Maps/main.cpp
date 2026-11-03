#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int n, m;
char grid[20][20];
bool visited[20][20];

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

auto isValidAndOpen(int r, int c) -> bool {
    if (r < 0 || c < 0 || r >= n || c >= m) {
        return false;
    }
    return true;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int startX, startY;
    while (std::cin >> n >> m && (n != 0 || m != 0)) {
        std::cin >> startX >> startY;
        startX--;
        startY--;

        for (int i{}; i < n; ++i) {
            for (int j{}; j < m; ++j) {
                std::cin >> grid[i][j];
            }
        }

        std::memset(visited, 0, sizeof(visited));
        visited[startX][startY] = true;
        int moveCount = 0;

        int r = startX, c = startY;
        while (true) {
            int nr = -1, nc = -1;
            for (int d{}; d < 4; ++d) {
                int tr = r + dir[d][0];
                int tc = c + dir[d][1];
                if (isValidAndOpen(tr, tc) && !visited[tr][tc] &&
                    grid[tr][tc] == '0') {
                    nr = tr;
                    nc = tc;
                    break;
                }
            }
            if (nr == -1) {
                break;
            }
            r = nr;
            c = nc;
            visited[r][c] = true;
            ++moveCount;
        }

        output << "\n";
        for (int i{}; i < n; ++i) {
            output << '|';
            for (int j{}; j < m; ++j) {
                output << "---|";
            }
            output << "\n|";
            for (int j{}; j < m; ++j) {
                bool visible = visited[i][j];
                if (!visible) {
                    for (int d{}; d < 4; ++d) {
                        int ni = i + dir[d][0];
                        int nj = j + dir[d][1];
                        if (isValidAndOpen(ni, nj) && visited[ni][nj]) {
                            visible = true;
                            break;
                        }
                    }
                }

                output << ' ';
                if (visible) {
                    output << grid[i][j];
                } else {
                    output << '?';
                }
                output << " |";
            }
            output << "\n";
        }
        output << '|';
        for (int i = 0; i < m; ++i) {
            output << "---|";
        }
        output << "\n\nNUMBER OF MOVEMENTS: " << moveCount << "\n";
    }
    std::cout << output.str();
}