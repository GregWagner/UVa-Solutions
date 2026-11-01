// 556 Amazing
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const int dr[] = {0, 1, 0, -1};
const int dc[] = {1, 0, -1, 0};

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int R, C;
    while (std::cin >> R >> C && R != 0 && C != 0) {
        std::vector<std::string> grid(R);
        for (int i{}; i < R; ++i) {
            std::cin >> grid[i];
        }

        std::vector<std::vector<bool>> passable(R, std::vector<bool>(C, false));
        std::vector<std::vector<int>> counts(R, std::vector<int>(C, 0));
        for (int r{}; r < R; ++r) {
            for (int c{}; c < C; ++c) {
                if (grid[r][c] == '0') {
                    passable[r][c] = true;
                }
            }
        }

        auto isPassable = [&](int r, int c, int dir) -> bool {
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            return nr >= 0 && nr < R && nc >= 0 && nc < C && passable[nr][nc];
        };

        int r{R - 1}, c{}, dir{};
        do {
            if (isPassable(r, c, (dir + 1) % 4)) {
                dir = (dir + 1) % 4;
            }
            while (!isPassable(r, c, dir)) {
                dir = (dir + 3) % 4;
            }
            r += dr[dir];
            c += dc[dir];
            if (passable[r][c])
                ++counts[r][c];
        } while (r != R - 1 || c != 0);

        std::vector<int> occur(5, 0);
        for (int rr{}; rr < R; ++rr) {
            for (int cc{}; cc < C; ++cc) {
                if (passable[rr][cc]) {
                    int v{counts[rr][cc]};
                    if (v > 4)
                        v = 4;
                    ++occur[v];
                }
            }
        }
        for (int i{}; i < 5; ++i) {
            output << std::setw(3) << occur[i];
        }
        output << '\n';
    }

    std::cout << output.str();
}
