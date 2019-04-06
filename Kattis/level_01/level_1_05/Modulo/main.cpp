/*
 * Modulo
 */
#include <iostream>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    bool a[45] {};

    int count {};
    for (int i {}; i < 10; ++i) {
        int num;
        std::cin >> num;
        num %= 42;
        if (!a[num]) {
            ++count;
            a[num] = true;
        }
    }
    std::cout << count << '\n';
}
