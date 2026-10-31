// 320 - Border
#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCases;
    if (!(std::cin >> testCases)) {
        return 0;
    }
    for (int caseNum{1}; caseNum <= testCases; ++caseNum) {
        int x, y;
        std::cin >> x >> y;
        std::string moves;
        std::cin >> moves;

        bool map[32][32] = {};

        for (char c : moves) {
            if (c == 'E') {
                if (x >= 0 && y - 1 >= 0 && x < 32 && y - 1 < 32)
                    map[x][y - 1] = true;
                ++x;
            } else if (c == 'N') {
                if (x >= 0 && y >= 0 && x < 32 && y < 32)
                    map[x][y] = true;
                ++y;
            } else if (c == 'W') {
                if (x - 1 >= 0 && y >= 0 && x - 1 < 32 && y < 32)
                    map[x - 1][y] = true;
                --x;
            } else if (c == 'S') {
                if (x - 1 >= 0 && y - 1 >= 0 && x - 1 < 32 && y - 1 < 32)
                    map[x - 1][y - 1] = true;
                --y;
            }
        }

        std::cout << "Bitmap #" << caseNum << "\n";
        for (int i = 31; i >= 0; --i) {
            for (int j = 0; j < 32; ++j) {
                std::cout << (map[j][i] ? 'X' : '.');
            }
            std::cout << '\n';
        }
        std::cout << '\n';
    }
}
