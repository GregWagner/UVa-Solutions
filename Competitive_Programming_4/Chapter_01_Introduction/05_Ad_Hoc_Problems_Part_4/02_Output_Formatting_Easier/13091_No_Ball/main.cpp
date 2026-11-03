#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int caseNum{1}; caseNum <= testCases; ++caseNum) {

        std::vector<std::string> grid(5);
        int footCol{-1};
        char footDir{' '};
        int creaseCol{-1};

        for (int i{}; i < 5; ++i) {
            std::cin >> grid[i];
            for (int j{}; j < 5; ++j) {
                if (grid[i][j] == '<' || grid[i][j] == '>') {
                    footCol = j;
                    footDir = grid[i][j];
                } else if (grid[i][j] == '|') {
                    creaseCol = j;
                }
            }
        }

        bool isNoBall = false;
        if (footDir == '>' && footCol > creaseCol) {
            isNoBall = true;
        } else if (footDir == '<' && footCol < creaseCol) {
            isNoBall = true;
        }

        output << "Case " << caseNum << ": ";
        if (isNoBall) {
            output << "No Ball\n";
        } else {
            output << "Thik Ball\n";
        }
    }
    std::cout << output.str();
}