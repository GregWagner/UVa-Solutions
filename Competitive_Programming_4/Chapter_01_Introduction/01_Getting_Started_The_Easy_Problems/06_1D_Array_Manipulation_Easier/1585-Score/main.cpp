#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases--) {
        int score {};
        int count { 1 };
        std::string s;
        std::cin >> s;
        for (size_t i {}; i < s.size(); ++i) {
            if (s[i] == 'X') {
                count = 1;
            } else {
                score += count++;
            }
        }
        output << score << '\n';
    }

    std::cout << output.str();
}
