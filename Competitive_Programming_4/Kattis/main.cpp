#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int cost{};
    for (int i{}; i < n; ++i) {
        int have, need, price;
        std::cin >> have >> need >> price;
        if (have < need) {
            cost += (need - have) * price;
        }
    }
    std::cout << cost << '\n';
}
