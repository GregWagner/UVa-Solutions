#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a[] = {0, 9, 25, 81, 289, 1089, 4225, 16641, 66049, 263169, 1050625,
        4198401, 16785409, 67125249, 268468225, 1073807361};
    int n;
    std::cin >> n;
    std::cout << a[n] << '\n';
}