#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static int letterWeight(char c) {
    int ascii{static_cast<unsigned char>(c)};
    int msb{-1};
    for (int i{30}; i >= 0; --i) {
        if (ascii & (1 << i)) {
            msb = i;
            break;
        }
    }
    int ones{0};
    int zeros{0};
    for (int i{msb}; i >= 0; --i) {
        if (ascii & (1 << i))
            ++ones;
        else
            ++zeros;
    }
    return ones * 500 + zeros * 250;
}

static int findBottom(const std::vector<std::string>& grid, int side) {
    for (int r{0}; r < 7; ++r) {
        std::string seg{(side == 0) ? grid[r].substr(0, 8)
                                    : grid[r].substr(10, 8)};
        if (seg == "\\______/")
            return r;
    }
    return -1;
}

static std::vector<std::string> makeSide(int bottomRow,
                                         const std::string& interior) {
    std::vector<std::string> rows(7, std::string(8, '.'));
    if (bottomRow >= 0 && bottomRow < 7)
        rows[bottomRow] = "\\______/";
    if (bottomRow - 1 >= 0)
        rows[bottomRow - 1] = "/" + interior + "\\";
    if (bottomRow - 2 >= 0)
        rows[bottomRow - 2] = "./....\\.";
    if (bottomRow - 3 >= 0)
        rows[bottomRow - 3] = "../..\\..";
    if (bottomRow - 4 >= 0)
        rows[bottomRow - 4] = ".../\\...";
    return rows;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int T{};
    if (!(std::cin >> T))
        return 0;
    for (int caseNum{1}; caseNum <= T; ++caseNum) {
        std::vector<std::string> grid(7);
        for (int i{0}; i < 7; ++i)
            std::cin >> grid[i];
        std::string sep;
        std::cin >> sep;

        int leftBottom{findBottom(grid, 0)};
        int rightBottom{findBottom(grid, 1)};

        std::string leftSeg{grid[leftBottom - 1].substr(0, 8)};
        std::string leftInterior{leftSeg.substr(1, 6)};
        if (static_cast<int>(leftInterior.size()) < 6)
            leftInterior.append(6 - leftInterior.size(), '.');

        std::string rightSeg{grid[rightBottom - 1].substr(10, 8)};
        std::string rightInterior{rightSeg.substr(1, 6)};
        if (static_cast<int>(rightInterior.size()) < 6)
            rightInterior.append(6 - rightInterior.size(), '.');

        long long leftSum{0};
        long long rightSum{0};
        for (char c : leftInterior)
            if (c >= 'A' && c <= 'Z')
                leftSum += letterWeight(c);
        for (char c : rightInterior)
            if (c >= 'A' && c <= 'Z')
                rightSum += letterWeight(c);

        int curState{};
        if (leftBottom == 6)
            curState = 0;
        else if (leftBottom == 5)
            curState = 1;
        else
            curState = 2;

        int expState{};
        if (leftSum > rightSum)
            expState = 0;
        else if (leftSum == rightSum)
            expState = 1;
        else
            expState = 2;

        output << "Case " << caseNum << ":\n";
        if (curState == expState) {
            output << "The figure is correct.\n";
        } else {
            int leftExpBottom{};
            int rightExpBottom{};
            if (expState == 0) {
                leftExpBottom = 6;
                rightExpBottom = 4;
            } else if (expState == 1) {
                leftExpBottom = 5;
                rightExpBottom = 5;
            } else {
                leftExpBottom = 4;
                rightExpBottom = 6;
            }

            std::vector<std::string> L{makeSide(leftExpBottom, leftInterior)};
            std::vector<std::string> R{makeSide(rightExpBottom, rightInterior)};
            for (int r{0}; r < 7; ++r) {
                output << L[r] << "||" << R[r] << "\n";
            }
        }
    }

    std::cout << output.str();
}