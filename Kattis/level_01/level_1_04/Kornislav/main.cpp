/*
 * Kornislav
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::vector<int> a;
    for (int i {}; i < 4; ++i) {
        int temp;
        std::cin >> temp;
        a.push_back(temp);
    }
    std::sort(a.begin(), a.end());
    std::cout << a[0] * a[2] << '\n';
}
