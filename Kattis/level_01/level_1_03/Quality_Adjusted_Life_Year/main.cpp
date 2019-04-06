/*
 * Quality-Adjusted Life-Year
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    double answer {};
    for (int i {}; i < n; ++i) {
        double q, y;
        std::cin >> q >> y;
        answer += q * y;
    }
    std::cout << answer << '\n';
}
