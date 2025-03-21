#include <iostream>
#include <sstream>

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    std::ostringstream output;
    int tea {};
    while (std::cin >> tea) {
        int answer {};
        for (int i {}; i < 5; ++i) {
            int guess {};
            std::cin >> guess;
            if (tea == guess) {
                ++answer;
            }
        }
        output << answer << '\n';
    }
    std::cout << output.str();
}
