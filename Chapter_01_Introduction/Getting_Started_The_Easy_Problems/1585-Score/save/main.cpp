/*
 * 1585 Score
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        std::string s;
        std::cin >> s;
        int score {};
        for (size_t i {}; i < s.size(); ++i) {
            int correct {};
            while (i < s.size() && s[i] == 'O') {
                ++correct;
                score += correct;
                ++i;
            }
        }
        output << score << '\n';
    }
    std::cout << output.str();
}
