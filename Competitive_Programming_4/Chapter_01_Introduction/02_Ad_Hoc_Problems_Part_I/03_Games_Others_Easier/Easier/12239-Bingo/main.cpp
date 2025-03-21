/*
 * Problem 12239 - Bingo!
 */
#include <iostream>
#include <sstream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::ostringstream output;
    int n, b;
    while (std::cin >> n >> b) {
        if (n == 0 && b == 0) {
            break;
        }
        bool a[100] {};
        std::vector<int> balls;
        for (int i {}; i < b; ++i) {
            int temp;
            std::cin >> temp;
            balls.push_back(temp);
        }
        for (size_t i {}; i < balls.size(); ++i) {
            for (size_t j {}; j < balls.size(); ++j) {
                a[std::abs(balls[i] - balls[j])] = true;
            }
        }
        bool covered {true};
        for (int i {}; i <= n; ++i) {
            if (!a[i]) {
                covered = false;
                break;
            }
        }
        output << (covered ? 'Y' : 'N') << '\n';
    }
    std::cout << output.str();
}
