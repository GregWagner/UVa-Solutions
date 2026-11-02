#include <algorithm>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int T;
    if (!(std::cin >> T)) return 0;
    bool first{true};
    for (int caseIdx = 0; caseIdx < T; ++caseIdx) {
        int n;
        std::cin >> n;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::string s;
        s.reserve(n);
        char c;
        while ((int)s.size() < n && std::cin.get(c)) {
            if (c == '\n' || c == '\r') continue;
            s.push_back(c);
        }

        std::string doubled = s + s;
        std::vector<std::pair<std::string, int>> indexedShifts(n);
        for (int i{}; i < n; ++i) {
            indexedShifts[i] = {doubled.substr(i, n), i};
        }

        // Sort cyclic shifts lexicographically
        sort(indexedShifts.begin(), indexedShifts.end());

        int targetIndex{};
        std::string bwt{};
        for (int i{}; i < n; ++i) {
            if (indexedShifts[i].second == 1) {
                targetIndex = i; // Track row index of rotation starting at 1 (S1)
            }
            bwt += indexedShifts[i].first.back(); // Take the last character
        }

        if (!first) {
            output << "\n";
        }
        first = false;

        output << targetIndex << "\n";

        for (int i{}; i < n; ++i) {
            output << bwt[i];
            if ((i + 1) % 50 == 0 && i + 1 < n) {
                output << "\n";
            }
        }
        output << "\n";
    }
    std::cout << output.str();
}
