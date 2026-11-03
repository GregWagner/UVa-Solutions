#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int n;
    int caseNum = 1;
    while (std::cin >> n) {
        int coolWordCount{};
        for (int i{}; i < n; ++i) {
            std::string s;
            std::cin >> s;

            int freq[26] = {0};
            for (char c : s) {
                freq[c - 'a']++;
            }

            std::set<int> uniqueFreqs;
            bool isCool{true};
            bool hasAny{};

            for (int f : freq) {
                if (f > 0) {
                    hasAny = true;
                    if (uniqueFreqs.count(f)) {
                        isCool = false;
                        break;
                    }
                    uniqueFreqs.insert(f);
                }
            }

            if (isCool && hasAny && uniqueFreqs.size() >= 2) {
                coolWordCount++;
            }
        }

        output << "Case " << caseNum++ << ": " << coolWordCount << "\n";
    }
    std::cout << output.str();
}