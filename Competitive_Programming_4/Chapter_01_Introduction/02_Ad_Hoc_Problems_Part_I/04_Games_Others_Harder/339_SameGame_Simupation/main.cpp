/*
 * 339 - SameGame Simulation
 *
 * Grid data is given bottom row first: cell (1,1) is the lower-left corner.
 * A value of 0..9 is a real cell; EMPTY (-1) is only used after a removal.
 * Output prints the top row first, indented by 4 spaces, cells joined by a
 * single space, an empty cell printed as a space (trailing spaces kept).
 */
#include <iostream>
#include <sstream>
#include <vector>

namespace {
constexpr int EMPTY = -1;
constexpr int MAXM = 10;
constexpr int MAXN = 40;

int grid[MAXM + 2][MAXN + 2];
bool seen[MAXM + 2][MAXN + 2];
int m, n;
} // namespace

// Remove the connected region of equal values containing (sr, sc) when it has
// at least two cells. Returns true if a removal happened.
static bool removeRegion(int sr, int sc) {
    int value = grid[sr][sc];
    if (value == EMPTY)
        return false;

    std::vector<std::pair<int, int>> stack;
    std::vector<std::pair<int, int>> region;
    stack.emplace_back(sr, sc);
    seen[sr][sc] = true;

    while (!stack.empty()) {
        int r = stack.back().first;
        int c = stack.back().second;
        stack.pop_back();
        region.emplace_back(r, c);

        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (nr < 1 || nr > m || nc < 1 || nc > n)
                continue;
            if (seen[nr][nc] || grid[nr][nc] != value)
                continue;
            seen[nr][nc] = true;
            stack.emplace_back(nr, nc);
        }
    }

    for (std::vector<std::pair<int, int>>::const_iterator it = region.begin();
         it != region.end(); ++it) {
        seen[it->first][it->second] = false;
    }

    if (region.size() < 2)
        return false;
    for (std::vector<std::pair<int, int>>::const_iterator it = region.begin();
         it != region.end(); ++it) {
        grid[it->first][it->second] = EMPTY;
    }
    return true;
}

// Cells fall down within each column, then fully empty columns slide left.
static void gravity() {
    for (int c = 1; c <= n; ++c) {
        int write = 1;
        for (int r = 1; r <= m; ++r) {
            if (grid[r][c] != EMPTY) {
                grid[write][c] = grid[r][c];
                ++write;
            }
        }
        for (int r = write; r <= m; ++r)
            grid[r][c] = EMPTY;
    }

    int write = 1;
    for (int c = 1; c <= n; ++c) {
        bool empty = true;
        for (int r = 1; r <= m; ++r) {
            if (grid[r][c] != EMPTY) {
                empty = false;
                break;
            }
        }
        if (empty)
            continue;
        if (write != c) {
            for (int r = 1; r <= m; ++r)
                grid[r][write] = grid[r][c];
        }
        ++write;
    }
    for (int c = write; c <= n; ++c) {
        for (int r = 1; r <= m; ++r)
            grid[r][c] = EMPTY;
    }
}

static bool won() {
    for (int r = 1; r <= m; ++r)
        for (int c = 1; c <= n; ++c)
            if (grid[r][c] != EMPTY)
                return false;
    return true;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int number = 0;
    while (std::cin >> m >> n && (m != 0 && n != 0)) {
        for (int r = 1; r <= m; ++r)
            for (int c = 1; c <= n; ++c)
                std::cin >> grid[r][c];

        bool gameWon = false;
        for (;;) {
            int r, c;
            std::cin >> r >> c;
            if (r == 0 && c == 0)
                break;
            if (gameWon)
                continue; // drain remaining selections
            if (r < 1 || r > m || c < 1 || c > n)
                continue;

            if (removeRegion(r, c)) {
                gravity();
                if (won())
                    gameWon = true;
            }
        }

        ++number;
        if (number > 1)
            std::cout << '\n';
        std::cout << "Grid " << number << ".\n";

        if (gameWon) {
            std::cout << "    Game Won\n";
        } else {
            for (int r = m; r >= 1; --r) {
                std::cout << "    ";
                for (int c = 1; c <= n; ++c) {
                    if (c > 1)
                        std::cout << ' ';
                    if (grid[r][c] == EMPTY)
                        std::cout << ' ';
                    else
                        std::cout << grid[r][c];
                }
                std::cout << '\n';
            }
        }
    }
}
