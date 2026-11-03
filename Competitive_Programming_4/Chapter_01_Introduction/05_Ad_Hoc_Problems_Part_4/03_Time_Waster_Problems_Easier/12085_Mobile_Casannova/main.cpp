#include <iostream>
#include <sstream>
#include <string>
#include <vector>

auto getCommonPrefixLength(const std::string& a, const std::string& b) -> int {
    int len{};
    while (len < a.length() && len < b.length() && a[len] == b[len]) {
        len++;
    }
    return len;
}

auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;

    int n, caseNum{1};
    while (std::cin >> n && n != 0) {
        std::vector<std::string> nums(n);
        for (int i{}; i < n; ++i) {
            std::cin >> nums[i];
        }

        output << "Case " << caseNum++ << ":\n";

        int i{};
        while (i < n) {
            int start{i};
            while (i + 1 < n && stoll(nums[i + 1]) == stoll(nums[i]) + 1) {
                i++;
            }

            if (start == i) {
                output << nums[start] << "\n";
            } else {
                std::string firstStr{nums[start]};
                std::string lastStr{nums[i]};
                int commonLen{getCommonPrefixLength(firstStr, lastStr)};
                output << firstStr << "-" << lastStr.substr(commonLen) << "\n";
            }
            i++;
        }
        output << "\n"; // Blank line after each test case
    }
    std::cout << output.str();
}
