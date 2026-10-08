/*
 * Problem 114 - Simulation Wizardry
 */
#include <iostream>
#include <sstream>

constexpr int MAX{51}; // 2 < m, n < 51 -> largest index is 50
constexpr int DIRS{4};

struct Bumper {
    int value;
    int cost;
    bool present;
};

static Bumper grid[MAX][MAX];

// 0 Right, 1 up, 2 left, 3 down
constexpr int dx[DIRS]{1, 0, -1, 0};
constexpr int dy[DIRS]{0, 1, 0, -1};

// A rebound is a clockwise 90 degree turn.
constexpr int turnRight(int direction) {
    return (direction + 3) & 3;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int m{}, n{}, wallCost{}, numberOfBumpers{};
    std::cin >> m >> n >> wallCost >> numberOfBumpers;
    for (int i{}; i < numberOfBumpers; ++i) {
        int x{}, y{}, bumperValue{}, bumperCost{};
        std::cin >> x >> y >> bumperValue >> bumperCost;
        grid[x - 1][y - 1] = {bumperValue, bumperCost, true};
    }

    const int lastX{m - 1};
    const int lastY{n - 1};

    std::ostringstream output;
    int totalScore{};
    int x{}, y{}, direction{}, lifetime{};
    while (std::cin >> x >> y >> direction >> lifetime) {
        --x;
        --y;
        int score{};
        // Each step costs one lifetime; the pre-decrement means a
        // lifetime-1 ball dies before moving and scores nothing
        while (--lifetime > 0) {
            int nx{x + dx[direction]};
            int ny{y + dy[direction]};
            bool hit{};
            if (nx <= 0 || nx >= lastX || ny <= 0 || ny >= lastY) {
                lifetime -= wallCost;
                hit = true;
            } else if (grid[nx][ny].present) {
                score += grid[nx][ny].value;
                lifetime -= grid[nx][ny].cost;
                hit = true;
            } else {
                x = nx;
                y = ny;
            }
            if (hit) {
                direction = turnRight(direction);
            }
        }
        totalScore += score;
        output << score << '\n';
    }
    output << totalScore << '\n';
    std::cout << output.str();
}
