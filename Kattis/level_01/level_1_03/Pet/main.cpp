/*
 * Pet
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int maxSum {};
    int number {};
    for (int i {1}; i <= 5; ++i) {
        int sum {};
        for (int j {}; j < 4; ++j) {
            int n;
            std::cin >> n;
            sum += n;
        }
        if (sum > maxSum) {
            maxSum = sum;
            number = i;
        }
    }
    std::cout << number << ' ' << maxSum << '\n';
}
