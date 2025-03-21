/*
 * 12015 Google is Feeling Lucky
 */
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::ostringstream output;
    int testCases {};
    int testCase {};
    std::cin >> testCases;
    while (testCases-- != 0) {
        int highScore {};
        std::vector<std::string> a;
        for (int i {}; i < 10; ++i) {
            std::string s;
            int score {};
            std::cin >> s >> score;
            if (score == highScore) {
                a.push_back(s); 
            } else if (score > highScore) {
                highScore = score;
                a.clear();
                a.push_back(s);
            }
        }
        output << "Case #" << ++testCase << ":\n";
        for (const auto &e : a) {
            output << e << '\n';
        }
    }
    std::cout << output.str();
}
