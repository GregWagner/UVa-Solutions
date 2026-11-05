#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int testNum{}; testNum < testCases; ++testNum) {
        int R, C;
        std::cin >> R >> C;
        std::vector<std::string> grid(R);
        for (int i{}; i < R; ++i) {
            std::cin >> grid[i];
        }
        int sardines{}, mackerels{}, salmons{}, groupers{};
        int turtles{}, dolphines{}, whales{}, sharks{};
        const int dr[4] = {-1, 1, 0, 0};
        const int dc[4] = {0, 0, -1, 1};
        for (int i{}; i < R; ++i) {
            for (int j{}; j < C; ++j) {
                if (grid[i][j] == '.') {
                    continue;
                }
                char ch{grid[i][j]};
                int top{i}, bottom{i}, left{j}, right{j};
                int area{};
                std::stack<std::pair<int, int>> st;
                st.emplace(i, j);
                grid[i][j] = '.';
                while (!st.empty()) {
                    std::pair<int, int> p{st.top()};
                    st.pop();
                    int r{p.first};
                    int c{p.second};
                    ++area;
                    if (r < top) {
                        top = r;
                    }
                    if (r > bottom) {
                        bottom = r;
                    }
                    if (c < left) {
                        left = c;
                    }
                    if (c > right) {
                        right = c;
                    }
                    for (int k{}; k < 4; ++k) {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        if (nr >= 0 && nr < R && nc >= 0 && nc < C &&
                            grid[nr][nc] == ch) {
                            grid[nr][nc] = '.';
                            st.emplace(nr, nc);
                        }
                    }
                }
                int width = bottom - top + 1;
                int height = right - left + 1;
                if (width > height)
                    std::swap(width, height);
                if (area != width * height) {
                    ++sharks;
                } else {
                    if (width == 1 && height == 1) {
                        ++sardines;
                    } else if (width == 1 && height == 2) {
                        ++mackerels;
                    } else if (width == 1 && height > 2) {
                        ++salmons;
                    } else if (width == height && width >= 2) {
                        ++turtles;
                    } else if (width == 2 && height > 2) {
                        ++groupers;
                    } else if (width == 3 && height > 3) {
                        ++dolphines;
                    } else if (width == 4 && height > 4) {
                        ++whales;
                    }
                }
            }
        }
        if (testNum > 0)
            output << '\n';
        output << sardines << ' ' << mackerels << ' ' << salmons << ' '
               << groupers << ' ' << turtles << ' ' << dolphines << ' '
               << whales << ' ' << sharks << '\n';
    }
    std::cout << output.str();
}
