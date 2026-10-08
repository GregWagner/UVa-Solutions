#include <algorithm>
#include <iostream>
#include <sstream>

auto main() -> int {
    std::ios_base::sync_with_stdio(false);

    std::ostringstream output;
    int testCases{};
    int test{};
    std::cin >> testCases;

    while (testCases--) {
        std::string start, end;
        std::cin >> start >> end;
        std::cout << "--- Starting ---------------------\n";
        std::cout << start << '\n' << end << '\n';

        // check if no changes needed
        if (start == end) {
            output << "Case " << ++test << ": 0\n";
            continue;
        }

        // check if a solution is possible
        size_t totalOnesT = std::count(end.begin(), end.end(), '1');
        size_t totalOnesS = std::count(start.begin(), start.end(), '1');
        size_t totalQuestionS = std::count(start.begin(), start.end(), '?');

        if (totalOnesS + totalQuestionS < totalOnesT) {
            output << "Case " << ++test << ": -1\n";
            continue;
        }

        // catagozize mismatches
        int mismatch1_0{};
        int mismatch0_1{};
        int mismatchQ_0{};
        int mismatchQ_1{};

        for (size_t i{}; i < start.size(); ++i) {
            if (start[i] == '1' && end[i] == '0') {
                ++mismatch1_0;
            } else if (start[i] == '0' && end[i] == '1') {
                ++mismatch0_1;
            } else if (start[i] == '?' && end[i] == '0') {
                ++mismatchQ_0;
            } else if (start[i] == '?' && end[i] == '1') {
                ++mismatchQ_1;
            }
        }

        auto totalMoves =
            std::max(mismatch0_1, mismatch1_0) + mismatchQ_0 + mismatchQ_1;

        output << totalMoves << '\n';
    }
    std::cout << output.str();
}
