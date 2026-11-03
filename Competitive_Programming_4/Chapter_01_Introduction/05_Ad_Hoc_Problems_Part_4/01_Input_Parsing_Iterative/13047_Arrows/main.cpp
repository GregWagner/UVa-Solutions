#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int testCases;
    std::cin >> testCases;
    for (int caseNum{1}; caseNum <= testCases; ++caseNum) {

        std::string s;
        std::cin >> s;

        int maxLength{-1};
        int n = s.length();

        for (int i{}; i < n; ++i) {
            if (s[i] == '>') {
                int len{1};
                int j = i - 1;
                while (j >= 0 && s[j] == '-') {
                    len++;
                    j--;
                }
                if (len > 1)
                    maxLength = std::max(maxLength, len);

                len = 1;
                j = i - 1;
                while (j >= 0 && s[j] == '=') {
                    len++;
                    j--;
                }
                if (len > 1) {
                    maxLength = std::max(maxLength, len);
                }

                maxLength = std::max(maxLength, 1);
            }

            if (s[i] == '<') {
                int len{1};
                int j = i + 1;
                while (j < n && s[j] == '-') {
                    len++;
                    j++;
                }
                if (len > 1)
                    maxLength = std::max(maxLength, len);

                len = 1;
                j = i + 1;
                while (j < n && s[j] == '=') {
                    len++;
                    j++;
                }
                if (len > 1) {
                    maxLength = std::max(maxLength, len);
                }

                maxLength = std::max(maxLength, 1);
            }
        }
        output << "Case " << caseNum << ": " << maxLength << "\n";
    }
    std::cout << output.str();
}