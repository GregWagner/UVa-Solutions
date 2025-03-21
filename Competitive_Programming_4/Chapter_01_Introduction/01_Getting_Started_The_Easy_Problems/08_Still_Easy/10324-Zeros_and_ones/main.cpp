/*
 * 10324 Zeros and Ones
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCase {};
    std::string s;
    while (std::cin >> s) {
        output << "Case " << ++testCase << ":\n";
        int testCases {};
        std::cin >> testCases;
        while (testCases--) {
            bool valid {true};
            int start {};
            int end {};
            std::cin >> start >> end;
            char c {s[start]};
            for (int i {std::min(start, end) + 1}; i <= std::max(start, end); ++i) {
                if (c != s[i]) {
                    valid = false;
                }
            }
            output << (valid ? "Yes\n" : "No\n");
        }
    }
    std::cout << output.str();
}
