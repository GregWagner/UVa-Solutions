#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int m, n;
    int caseNum = 1;
    while (std::cin >> m >> n && (m != 0 || n != 0)) {
        output << "Triangular Museum " << caseNum++ << "\n";

        int height = m * n;
        int width = 2 * m * n;

        std::vector<std::string> grid(height, std::string(width, ' '));

        for (int level = 0; level < n; ++level) {
            int triCount = level + 1;
            for (int j = 0; j < triCount; ++j) {
                int apexLeft = (n - 1 - level) * m + 2 * m * j + (m - 1);
                for (int k = 0; k < m; ++k) {
                    int row = level * m + k;
                    int left = apexLeft - k;
                    int right = apexLeft + 1 + k;
                    grid[row][left] = '/';
                    grid[row][right] = '\\';
                    if (k == m - 1) {
                        for (int col = left + 1; col < right; ++col) {
                            grid[row][col] = '_';
                        }
                    }
                }
            }
        }

        for (int i = 0; i < height; ++i) {
            int lastIdx = width - 1;
            while (lastIdx >= 0 && grid[i][lastIdx] == ' ') {
                --lastIdx;
            }
            for (int j = 0; j <= lastIdx; ++j) {
                output << grid[i][j];
            }
            output << "\n";
        }
        output << "\n";
    }

    std::cout << output.str();
}