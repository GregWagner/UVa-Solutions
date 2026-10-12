/*
 * 379 - Hi-Q
 */
#include <iostream>
#include <sstream>
#include <vector>

namespace {
// 1..33 inside the cross, 0 marks a non-hole cell.
constexpr int HOLE[7][7] = {
    {0, 0, 1, 2, 3, 0, 0},        {0, 0, 4, 5, 6, 0, 0},
    {7, 8, 9, 10, 11, 12, 13},    {14, 15, 16, 17, 18, 19, 20},
    {21, 22, 23, 24, 25, 26, 27}, {0, 0, 28, 29, 30, 0, 0},
    {0, 0, 31, 32, 33, 0, 0},
};

struct Jump {
    int from;
    int over;
    int to;
};
} // namespace

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    // Precompute every jump: source, jumped peg, landing hole.
    std::vector<Jump> jumps;
    const int DR[4] = {0, 0, 1, -1};
    const int DC[4] = {1, -1, 0, 0};
    for (int r = 0; r < 7; ++r) {
        for (int c = 0; c < 7; ++c) {
            if (HOLE[r][c] == 0) {
                continue;
            }
            for (int d = 0; d < 4; ++d) {
                int r1 = r + DR[d], c1 = c + DC[d];
                int r2 = r + 2 * DR[d], c2 = c + 2 * DC[d];
                if (r1 < 0 || r1 >= 7 || c1 < 0 || c1 >= 7) {
                    continue;
                }
                if (r2 < 0 || r2 >= 7 || c2 < 0 || c2 >= 7) {
                    continue;
                }
                if (HOLE[r1][c1] == 0 || HOLE[r2][c2] == 0) {
                    continue;
                }
                jumps.push_back({HOLE[r][c], HOLE[r1][c1], HOLE[r2][c2]});
            }
        }
    }

    int instances;
    std::cin >> instances;

    output << "HI Q OUTPUT\n";
    for (int t = 0; t < instances; ++t) {
        bool peg[34] = {false};
        int hole;
        while (std::cin >> hole && hole != 0) {
            peg[hole] = true;
        }

        while (true) {
            const Jump* best = nullptr;
            for (const Jump& j : jumps) {
                if (!peg[j.from] || !peg[j.over] || peg[j.to]) {
                    continue;
                }
                if (best == nullptr || j.to > best->to ||
                    (j.to == best->to && j.from > best->from)) {
                    best = &j;
                }
            }
            if (best == nullptr) {
                break;
            }
            peg[best->from] = false;
            peg[best->over] = false;
            peg[best->to] = true;
        }

        int sum = 0;
        for (int i = 1; i <= 33; ++i) {
            if (peg[i]) {
                sum += i;
            }
        }
        output << sum << '\n';
    }
    output << "END OF OUTPUT\n";
    std::cout << output.str();
}
