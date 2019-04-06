/*
 * Cold-puter Science
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int n;
    std::cin >> n;
    int count {};
    for (int i {}; i < n; ++i) {
        int temp;
        std::cin >> temp;
        if (temp < 0) {
            ++count;
        }
    }
    std::cout << count << '\n';
}
