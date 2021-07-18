#include <iostream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::ostringstream output;
    int teaType {};
    while (std::cin >> teaType) {
        int correctCount {};
        for (int i {}; i < 5; ++i) {
            int guess;
            std::cin >> guess;
            if (guess == teaType) {
                ++correctCount;
            }
        }
        output << correctCount << '\n';
    }
    std::cout << output.str();
}
