// 11074 - Draw Grid
#include <iostream>

auto printHorizontalBorderLine(int totalSize, int thickness) -> void {
    for (int i{}; i < thickness; ++i) {
        for (int j{}; j < totalSize; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int testCase{1};

    int smallestSquare, thickness, gridSize;
    while (std::cin >> smallestSquare >> thickness >> gridSize) {
        if (smallestSquare == 0 && thickness == 0 && gridSize == 0) {
            break;
        }

        int totalSize =
            (gridSize + 1) * thickness + (gridSize * smallestSquare);
        std::cout << "Case " << testCase++ << ":\n";

        printHorizontalBorderLine(totalSize, thickness);

        for (int row{0}; row < gridSize; ++row) {
            for (int smallRow{0}; smallRow < smallestSquare; ++smallRow) {
                for (int line{}; line < thickness; ++line) {
                    std::cout << '*';
                }
                for (int col{}; col < gridSize; ++col) {
                    for (int i{}; i < smallestSquare; ++i) {
                        std::cout << '.';
                    }
                    for (int t{}; t < thickness; ++t) {
                        std::cout << '*';
                    }
                }
                std::cout << '\n';
            }
            printHorizontalBorderLine(totalSize, thickness);
        }
        std::cout << '\n';
    }
}
