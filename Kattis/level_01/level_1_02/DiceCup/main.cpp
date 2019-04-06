/*
 * Dice Cup
 */
#include <iostream>
#include <sstream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int a[50] {};
    for (int i {0}; i < 50; ++i) {
        a[i] = 0;
    }
    std::ostringstream output;
    int first, second;
    std::cin >> first >> second;
    for (int i {1}; i <= first; ++i) {
        for (int j {1}; j <= second; ++j) {
            ++a[i + j];
        }
    }
    int max {};
    for (int i {0}; i < 50; ++i) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    for (int i {0}; i < 50; ++i) {
        if (a[i] == max) {
            output << i << '\n';
        }
    }
    std::cout << output.str();
}
